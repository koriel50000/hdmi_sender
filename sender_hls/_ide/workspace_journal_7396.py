# 2026-08-10T18:27:01.405209200
import vitis

client = vitis.create_client()
client.set_workspace(path="sender_hls")

comp = client.get_component(name="sender_hls")
comp.run(operation="SYNTHESIS")

comp.run(operation="PACKAGE")

vitis.dispose()

