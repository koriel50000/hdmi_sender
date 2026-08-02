# 2026-07-26T08:41:45.915206800
import vitis

client = vitis.create_client()
client.set_workspace(path="sender_hls")

vitis.dispose()

