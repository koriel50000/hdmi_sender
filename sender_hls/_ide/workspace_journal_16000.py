# 2026-07-25T18:36:11.889571600
import vitis

client = vitis.create_client()
client.set_workspace(path="sender_hls")

comp = client.create_hls_component(name = "sender_hls",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

cfg = client.get_config_file(path="E:\workspace\IntelliJ\hdmi_sender\sender_hls\sender_hls\hls_config.cfg")

cfg.set_values(key="syn.file", values=["../C_source/define.h", "../C_source/sender.cpp"])

cfg.set_values(key="tb.file", values=["../C_source/sender_test.cpp"])

cfg = client.get_config_file(path="/e:/workspace/IntelliJ/hdmi_sender/sender_hls/sender_hls/hls_config.cfg")

cfg.set_value(section="hls", key="syn.top", value="pattern_sender")

comp = client.get_component(name="sender_hls")
comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="PACKAGE")

vitis.dispose()

