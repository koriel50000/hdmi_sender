# 2026-07-27T19:33:56.804427600
import vitis

client = vitis.create_client()
client.set_workspace(path="sender_hls")

vitis.dispose()

