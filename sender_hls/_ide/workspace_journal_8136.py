# 2026-08-08T09:29:46.173873600
import vitis

client = vitis.create_client()
client.set_workspace(path="sender_hls")

comp = client.get_component(name="sender_hls")
comp.run(operation="SYNTHESIS")

comp.run(operation="PACKAGE")

vitis.dispose()

