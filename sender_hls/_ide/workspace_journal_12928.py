# 2026-08-13T18:57:40.655479500
import vitis

client = vitis.create_client()
client.set_workspace(path="sender_hls")

comp = client.get_component(name="sender_hls")
comp.run(operation="SYNTHESIS")

comp.run(operation="PACKAGE")

comp.run(operation="SYNTHESIS")

comp.run(operation="PACKAGE")

comp.run(operation="SYNTHESIS")

comp.run(operation="PACKAGE")

vitis.dispose()

