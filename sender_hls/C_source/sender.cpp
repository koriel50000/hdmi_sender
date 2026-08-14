#include "sender.hpp"

void write_params(ap_uint<64>* params, fifo<axis_data64>& ins) {
    int ptr = 0;
	axis_data64 pkt;

    static constexpr int param_counts[] = {
        // YuNetBackbone stage0
        // Conv_head
        16 * 9 + 16 * 4,
        // Conv_head ConvDPUnit
        16 * 1 * 4 + 16 * 4,
        16 * 1 + 16 * 4,
        // YuNetBackbone stage1
        // YuNetBackbone Conv4layerBlock 1
        16 * 1 + 16 * 4,
        16 * 1 + 16 * 4,
        // YuNetBackbone Conv4layerBlock 2
        64 * 1 + 64 * 4,
        64 * 1 + 64 * 4,
        // YuNetBackbone stage2
        // YuNetBackbone Conv4layerBlock 1
        64 * 1 * 4 + 64 * 4,
        64 * 1 + 64 * 4,
        // YuNetBackbone Conv4layerBlock 2
        64 * 1 * 4 + 64 * 4,
        64 * 1 + 64 * 4,
        // YuNetBackbone stage3
        // YuNetBackbone Conv4layerBlock 1
        64 * 1 * 4 + 64 * 4,
        64 * 1 + 64 * 4,
        // YuNetBackbone Conv4layerBlock 2
        64 * 1 * 4 + 64 * 4,
        64 * 1 + 64 * 4,
        // YuNetBackbone stage4
        // YuNetBackbone Conv4layerBlock 1
        64 * 1 * 4 + 64 * 4,
        64 * 1 + 64 * 4,
        // YuNetBackbone Conv4layerBlock 2
        64 * 1 * 4 + 64 * 4,
        64 * 1 + 64 * 4,
        // YuNetBackbone stage5
        // YuNetBackbone Conv4layerBlock 1
        64 * 1 * 4 + 64 * 4,
        64 * 1 + 64 * 4,
        // YuNetBackbone Conv4layerBlock 2
        64 * 1 * 4 + 64 * 4,
        64 * 1 + 64 * 4,

        // TFPN stride32
        // TFPN ConvDPUnit
        64 * 1 * 4 + 64 * 4,
        64 * 1 + 64 * 4,
        // TFPN stride16
        // TFPN ConvDPUnit
        64 * 1 * 4 + 64 * 4,
        64 * 1 + 64 * 4,
        // TFPN stride8
        // TFPN ConvDPUnit
        64 * 1 * 4 + 64 * 4,
        64 * 1 + 64 * 4,
        // YuNet_Head stride8
        // YuNet_Head shared ConvDPUnit
        64 * 1 * 4 + 64 * 4,
        64 * 1 + 64 * 4,
        // YuNet_Head stride16
        // YuNet_Head shared ConvDPUnit
        64 * 1 * 4 + 64 * 4,
        64 * 1 + 64 * 4,
        // YuNet_Head stride32
        // YuNet_Head shared ConvDPUnit
        64 * 1 * 4 + 64 * 4,
        64 * 1 + 64 * 4,

        // YuNet_Head cls ConvDPUnit
        // YuNet_Head stride8
        1 * 1 * 4 + 1 * 4,
        1 * 1 + 1 * 4,
        // YuNet_Head stride16
        1 * 1 * 4 + 1 * 4,
        1 * 1 + 1 * 4,
        // YuNet_Head stride32
        1 * 1 * 4 + 1 * 4,
        1 * 1 + 1 * 4,

        // YuNet_Head bbox ConvDPUnit
        // YuNet_Head stride8
        4 * 1 * 4 + 4 * 4,
        4 * 1 + 4 * 4,
        // YuNet_Head stride16
        4 * 1 * 4 + 4 * 4,
        4 * 1 + 4 * 4,
        // YuNet_Head stride32
        4 * 1 * 4 + 4 * 4,
        4 * 1 + 4 * 4,

        // YuNet_Head obj ConvDPUnit
        // YuNet_Head stride8
        1 * 1 * 4 + 1 * 4,
        1 * 1 + 1 * 4,
        // YuNet_Head stride16
        1 * 1 * 4 + 1 * 4,
        1 * 1 + 1 * 4,
        // YuNet_Head stride32
        1 * 1 * 4 + 1 * 4,
        1 * 1 + 1 * 4,

        // YuNet_Head kps ConvDPUnit
        // YuNet_Head stride8
        10 * 1 * 4 + 10 * 4,
        10 * 1 + 10 * 4,
        // YuNet_Head stride16
        10 * 1 * 4 + 10 * 4,
        10 * 1 + 10 * 4,
        // YuNet_Head stride32
        10 * 1 * 4 + 10 * 4,
        10 * 1 + 10 * 4
    };
    
    for (int j = 0; j < sizeof(param_counts) / sizeof(param_counts[0]); j++) {
        for (int i = 0; i < param_counts[j]; i++) {
            pkt.data = params[ptr++];
            pkt.last = (i == param_counts[j] - 1);
            ins.write(pkt);
        }
    }
}

void read_detects(fifo<axis_data8>& outs, Detect detects[MAX_DETECTS], ap_uint<8>& count) {
#pragma HLS INLINE off

    axis_data8 data;
    data = outs.read();
    count = data.data;

    for (int i = 0; i < MAX_DETECTS; i++) {
        if (i < count) {
            axis_data8 dats[16];
#pragma HLS ARRAY_PARTITION variable=dats complete

            for (int j = 0; j < 16; j++) {
#pragma HLS PIPELINE
                dats[j] = outs.read();
            }

            detects[i].x1 = dats[0].data * 4 + 320;
            detects[i].y1 = dats[1].data * 4 + 40;
            detects[i].x2 = dats[2].data * 4 + 320;
            detects[i].y2 = dats[3].data * 4 + 40;

            for (int k = 0; k < 5; k++) {
#pragma HLS UNROLL
                detects[i].kps_x[k] = dats[6 + k * 2].data * 4 + 320;
                detects[i].kps_y[k] = dats[7 + k * 2].data * 4 + 40;
            }
        }
    }
}

void pattern_sender(fifo<pixel_t>& pin, fifo<pixel_t>& pout,
    fifo<axis_data64>& yunet_ins, fifo<axis_data8>& yunet_outs,
    ap_uint<64>* params, ap_uint<32> params_size)
{
#pragma HLS INTERFACE axis port=pin
#pragma HLS INTERFACE axis port=pout
#pragma HLS INTERFACE axis port=yunet_ins
#pragma HLS INTERFACE axis port=yunet_outs
#pragma HLS INTERFACE m_axi port=params offset=slave bundle=gmem
#pragma HLS INTERFACE s_axilite port=params bundle=ctrl
#pragma HLS INTERFACE s_axilite port=params_size bundle=ctrl
#pragma HLS INTERFACE s_axilite port=return bundle=ctrl

    static Detect detects[MAX_DETECTS];
    static ap_uint<8> detect_count = 0;

    pixel_t p, ptmp;
    p.data = 0;
    p.keep = p.strb = 0x7;
    p.user = p.last = p.id = p.dest = 0;

    int ux = 0;
    int uy = 0;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
#pragma HLS PIPELINE
            ptmp = pin.read();
            ap_uint<24> d = ptmp.data;

            bool detected = false;
            for (int i = 0; i < MAX_DETECTS; i++) {
#pragma HLS UNROLL
                if (i < detect_count) {
                    if (x >= detects[i].x1 && x <  detects[i].x2 &&
                        y >= detects[i].y1 && y <  detects[i].y2)
                    {
                        detected = true;
                    }
                }
            }
            if (detected) {
                p.data = 0xff0000;
            } else {
                p.data = d;            
            }

            p.user[0] = (x == 0 && y == 0);
            p.last = (x == WIDTH - 1);
            pout.write(p);

            if (320 <= y && y < 320 + 640 && 40 <= x && x < 40 + 640) {
                if (((x - 320) & 0x3) == 0 && ((y - 40) & 0x3) == 0) {
                    axis_data64 image;
                    image.data = d;
                    image.last = (ux == 159 && uy == 159);
                    yunet_ins.write(image);
                    ux++;
                    if (ux == 160) {
                        ux = 0;
                        uy++;
                    }
                }
            }
        }
    }

    write_params(params, yunet_ins);
    read_detects(yunet_outs, detects, detect_count);
}
