// Pattern Sender (HLS) for PYNQ 2021.07.13 Naoki F., AIT
// ライセンスについては LICENSE.txt を参照してください．

#include <ap_int.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>

const int WIDTH = 1280;
const int HEIGHT = 720;
const int MAX_DETECTS = 64;

struct Detect {
    ap_uint<8> x1;
    ap_uint<8> y1;
    ap_uint<8> x2;
    ap_uint<8> y2;

    ap_uint<16> score;

    ap_uint<8> kps_x[5];
    ap_uint<8> kps_y[5];
};

typedef ap_axiu<24,1,1,1> pixel_t;
// @see ug1399, HLS Programmers Guide > Customizing-AXI4-Stream-Interfaces
typedef ap_axis<64, 0, 0, 0, (AXIS_ENABLE_DATA | AXIS_ENABLE_LAST), true> axis_data64;
typedef ap_axis<8, 0, 0, 0, (AXIS_ENABLE_DATA | AXIS_ENABLE_LAST), true> axis_data8;

void pattern_sender(hls::stream<pixel_t>&, hls::stream<pixel_t>&,
    hls::stream<axis_data64>&, hls::stream<axis_data8>&);
