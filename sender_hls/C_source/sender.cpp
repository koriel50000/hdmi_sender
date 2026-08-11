// Pattern Sender (HLS) for PYNQ 2021.07.13 Naoki F., AIT
// ライセンスについては LICENSE.txt を参照してください．

#include "define.h"

void write_params(ap_uint<64>* weight, hls::stream<axis_data64>& ins) {
    int ptr = 0;
	axis_data64 pkt;
	pkt.last = 0;

	// YuNetBackbone stage0
	// Conv_head

	// torch.Size([16, 3, 3, 3])
	for (int i = 0; i < 16 * 9; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([16, 7])
	for (int i = 0; i < 16 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// Conv_head ConvDPUnit

	// torch.Size([16, 1, 1, 16])
	for (int i = 0; i < 16 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([16, 14])
	for (int i = 0; i < 16 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([16, 1, 1, 9])
	for (int i = 0; i < 16 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([16, 7])
	for (int i = 0; i < 16 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNetBackbone stage1
	// YuNetBackbone Conv4layerBlock 1

	// torch.Size([16, 1, 1, 16])
	for (int i = 0; i < 16 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([16, 14])
	for (int i = 0; i < 16 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([16, 1, 1, 9])
	for (int i = 0; i < 16 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([16, 7])
	for (int i = 0; i < 16 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNetBackbone Conv4layerBlock 2

	// torch.Size([64, 1, 1, 16])
	for (int i = 0; i < 64 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 14])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([64, 1, 1, 9])
	for (int i = 0; i < 64 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 7])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNetBackbone stage2
	// YuNetBackbone Conv4layerBlock 1

	// torch.Size([64, 1, 1, 64])
	for (int i = 0; i < 64 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 14])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([64, 1, 1, 9])
	for (int i = 0; i < 64 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 7])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNetBackbone Conv4layerBlock 2

	// torch.Size([64, 1, 1, 64])
	for (int i = 0; i < 64 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 14])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([64, 1, 1, 9])
	for (int i = 0; i < 64 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 7])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNetBackbone stage3
	// YuNetBackbone Conv4layerBlock 1

	// torch.Size([64, 1, 1, 64])
	for (int i = 0; i < 64 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 14])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([64, 1, 1, 9])
	for (int i = 0; i < 64 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 7])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNetBackbone Conv4layerBlock 2

	// torch.Size([64, 1, 1, 64])
	for (int i = 0; i < 64 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 14])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([64, 1, 1, 9])
	for (int i = 0; i < 64 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 7])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNetBackbone stage4
	// YuNetBackbone Conv4layerBlock 1

	// torch.Size([64, 1, 1, 64])
	for (int i = 0; i < 64 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 14])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([64, 1, 1, 9])
	for (int i = 0; i < 64 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 7])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNetBackbone Conv4layerBlock 2

	// torch.Size([64, 1, 1, 64])
	for (int i = 0; i < 64 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 14])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([64, 1, 1, 9])
	for (int i = 0; i < 64 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 7])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNetBackbone stage5
	// YuNetBackbone Conv4layerBlock 1

	// torch.Size([64, 1, 1, 64])
	for (int i = 0; i < 64 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 14])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([64, 1, 1, 9])
	for (int i = 0; i < 64 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 7])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNetBackbone Conv4layerBlock 2

	// torch.Size([64, 1, 1, 64])
	for (int i = 0; i < 64 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 14])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([64, 1, 1, 9])
	for (int i = 0; i < 64 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 7])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// TFPN stride32
	// TFPN ConvDPUnit

	// torch.Size([64, 1, 1, 64])
	for (int i = 0; i < 64 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 14])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([64, 1, 1, 9])
	for (int i = 0; i < 64 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 7])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// TFPN stride16
	// TFPN ConvDPUnit

	// torch.Size([64, 1, 1, 64])
	for (int i = 0; i < 64 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 14])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([64, 1, 1, 9])
	for (int i = 0; i < 64 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 7])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// TFPN stride8
	// TFPN ConvDPUnit

	// torch.Size([64, 1, 1, 64])
	for (int i = 0; i < 64 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 14])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([64, 1, 1, 9])
	for (int i = 0; i < 64 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 7])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNet_Head stride8
	// YuNet_Head shared ConvDPUnit

	// torch.Size([64, 1, 1, 64])
	for (int i = 0; i < 64 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 14])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([64, 1, 1, 9])
	for (int i = 0; i < 64 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 7])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNet_Head stride16
	// YuNet_Head shared ConvDPUnit

	// torch.Size([64, 1, 1, 64])
	for (int i = 0; i < 64 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 14])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([64, 1, 1, 9])
	for (int i = 0; i < 64 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 7])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNet_Head stride32
	// YuNet_Head shared ConvDPUnit

	// torch.Size([64, 1, 1, 64])
	for (int i = 0; i < 64 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 14])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([64, 1, 1, 9])
	for (int i = 0; i < 64 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([64, 7])
	for (int i = 0; i < 64 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNet_Head cls ConvDPUnit
	// YuNet_Head stride8

	// torch.Size([1, 1, 1, 64])
	for (int i = 0; i < 1 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([1, 14])
	for (int i = 0; i < 1 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([1, 1, 1, 9])
	for (int i = 0; i < 1 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([1, 14])
	for (int i = 0; i < 1 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNet_Head stride16

	// torch.Size([1, 1, 1, 64])
	for (int i = 0; i < 1 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([1, 14])
	for (int i = 0; i < 1 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([1, 1, 1, 9])
	for (int i = 0; i < 1 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([1, 14])
	for (int i = 0; i < 1 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNet_Head stride32

	// torch.Size([1, 1, 1, 64])
	for (int i = 0; i < 1 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([1, 14])
	for (int i = 0; i < 1 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([1, 1, 1, 9])
	for (int i = 0; i < 1 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([1, 14])
	for (int i = 0; i < 1 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNet_Head bbox ConvDPUnit
	// YuNet_Head stride8

	// torch.Size([4, 1, 1, 64])
	for (int i = 0; i < 4 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([4, 14])
	for (int i = 0; i < 4 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([4, 1, 1, 9])
	for (int i = 0; i < 4 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([4, 14])
	for (int i = 0; i < 4 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNet_Head stride16

	// torch.Size([4, 1, 1, 64])
	for (int i = 0; i < 4 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([4, 14])
	for (int i = 0; i < 4 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([4, 1, 1, 9])
	for (int i = 0; i < 4 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([4, 14])
	for (int i = 0; i < 4 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNet_Head stride32

	// torch.Size([4, 1, 1, 64])
	for (int i = 0; i < 4 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([4, 14])
	for (int i = 0; i < 4 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([4, 1, 1, 9])
	for (int i = 0; i < 4 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([4, 14])
	for (int i = 0; i < 4 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNet_Head obj ConvDPUnit
	// YuNet_Head stride8

	// torch.Size([1, 1, 1, 64])
	for (int i = 0; i < 1 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([1, 14])
	for (int i = 0; i < 1 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([1, 1, 1, 9])
	for (int i = 0; i < 1 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([1, 14])
	for (int i = 0; i < 1 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNet_Head stride16

	// torch.Size([1, 1, 1, 64])
	for (int i = 0; i < 1 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([1, 14])
	for (int i = 0; i < 1 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([1, 1, 1, 9])
	for (int i = 0; i < 1 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([1, 14])
	for (int i = 0; i < 1 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNet_Head stride32

	// torch.Size([1, 1, 1, 64])
	for (int i = 0; i < 1 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([1, 14])
	for (int i = 0; i < 1 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([1, 1, 1, 9])
	for (int i = 0; i < 1 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([1, 14])
	for (int i = 0; i < 1 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNet_Head kps ConvDPUnit
	// YuNet_Head stride8

	// torch.Size([10, 1, 1, 64])
	for (int i = 0; i < 10 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([10, 14])
	for (int i = 0; i < 10 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([10, 1, 1, 9])
	for (int i = 0; i < 10 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([10, 14])
	for (int i = 0; i < 10 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNet_Head stride16

	// torch.Size([10, 1, 1, 64])
	for (int i = 0; i < 10 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([10, 14])
	for (int i = 0; i < 10 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([10, 1, 1, 9])
	for (int i = 0; i < 10 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([10, 14])
	for (int i = 0; i < 10 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// YuNet_Head stride32

	// torch.Size([10, 1, 1, 64])
	for (int i = 0; i < 10 * 1*4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([10, 14])
	for (int i = 0; i < 10 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}

	// torch.Size([10, 1, 1, 9])
	for (int i = 0; i < 10 * 1; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}
	// torch.Size([10, 14])
	for (int i = 0; i < 10 * 4; i++) {
		pkt.data = weight[ptr++];
		ins.write(pkt);
	}    
    // TODO weight+threshold毎にループ回数を合計してループにする。ループにlast = 1を忘れずに。
}

void read_detects(hls::stream<axis_data8>& yunet_out, Detect detects[MAX_DETECTS], ap_uint<8>& count) {
#pragma HLS INLINE off

    axis_data8 data;
    data = yunet_out.read();
    count = data.data;

    for (int i = 0; i < MAX_DETECTS; i++) {
        if (i < count) {
            axis_data8 dats[16];
#pragma HLS ARRAY_PARTITION variable=dats complete

            // Python:
            // dats = recv_output(16)
            for (int j = 0; j < 16; j++) {
#pragma HLS PIPELINE
                dats[j] = yunet_out.read();
            }

            detects[i].x1 = dats[0].data;
            detects[i].y1 = dats[1].data;
            detects[i].x2 = dats[2].data;
            detects[i].y2 = dats[3].data;

            for (int k = 0; k < 5; k++) {
#pragma HLS UNROLL
                detects[i].kps_x[k] = dats[6 + k * 2].data;
                detects[i].kps_y[k] = dats[7 + k * 2].data;
            }
        }
    }
}

void pattern_sender(hls::stream<pixel_t>& pin, hls::stream<pixel_t>& pout,
    hls::stream<axis_data64>& yunet_in, hls::stream<axis_data8>& yunet_out,
    ap_uint<64>* weight, ap_uint<32> weight_size)
{
#pragma HLS INTERFACE axis port=pin
#pragma HLS INTERFACE axis port=pout
#pragma HLS INTERFACE axis port=yunet_in
#pragma HLS INTERFACE axis port=yunet_out
#pragma HLS INTERFACE m_axi port=weight offset=slave bundle=gmem
#pragma HLS INTERFACE s_axilite port=weight bundle=ctrl
#pragma HLS INTERFACE s_axilite port=weight_size bundle=ctrl
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
                p.data = 0xFF0000;
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
                    yunet_in.write(image);
                    ux++;
                    if (ux == 160) {
                        ux = 0;
                        uy++;
                    }
                }
            }
        }
    }

    write_params(weight, yunet_in);
    read_detects(yunet_out, detects, detect_count);
}
