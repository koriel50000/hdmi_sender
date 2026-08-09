# 2026-08-01T08:50:28.290167400
import vitis

client = vitis.create_client()
client.set_workspace(path="sender_hls")

comp = client.get_component(name="sender_hls")
comp.run(operation="SYNTHESIS")

comp.run(operation="PACKAGE")

comp.run(operation="SYNTHESIS")

comp.run(operation="PACKAGE")

comp.run(operation="SYNTHESIS")

vitis.dispose()

