// Pattern Sender (HLS) for PYNQ 2021.07.13 Naoki F., AIT
// ライセンスについては LICENSE.txt を参照してください．

#include "define.h"

void pattern_sender (hls::stream<pixel_t> &pin, hls::stream<pixel_t> &pout)
{
#pragma HLS INTERFACE s_axilite port=return bundle=ctrl
#pragma HLS INTERFACE axis port=pin
#pragma HLS INTERFACE axis port=pout

    pixel_t p, ptmp;
    p.data = 0;
    p.keep = p.strb = 0x7;
    p.user = p.last = p.id = p.dest = 0;
    ap_uint<9> col_x;
    ap_uint<8> col_y;
    const ap_uint<8> zero = 0x00;
    const ap_uint<8> full = 0xff;
    int frame = 0;
    
    for (int y = 0; y < 720; y++) {
        for (int x = 0; x < 1280; x++) {
#pragma HLS PIPELINE
            pin >> ptmp;
            if (160 <= x && x < 640 && 160 <= y && y < 320) {
                int n = x / 160;
                p.data.range(23, 16) = (n == 1) ? full : zero; // R
                p.data.range(15,  8) = (n == 2) ? full : zero; // B
                p.data.range( 7,  0) = (n == 3) ? full : zero; // G
            } else {
                ap_uint<24> d = ptmp.data;
                p.data.range(23, 16) = d.range(23, 16); // R
                p.data.range(15,  8) = d.range( 7,  0); // B
                p.data.range( 7,  0) = d.range(15,  8); // G
            }
            p.user[0] = (x == 0 && y == 0);
            p.last    = (x == 1279);
            pout << p;
        }
    }
}