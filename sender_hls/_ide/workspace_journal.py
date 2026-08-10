# 2026-08-10T21:46:54.623913500
import vitis

client = vitis.create_client()
client.set_workspace(path="sender_hls")

comp = client.get_component(name="sender_hls")
comp.run(operation="SYNTHESIS")

comp.run(operation="PACKAGE")

comp.run(operation="SYNTHESIS")

comp.run(operation="PACKAGE")

