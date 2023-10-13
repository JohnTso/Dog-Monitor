BOARD?=arduino:mbed:nano33ble
PORT?=/dev/cu.usbmodem11101
BUILD=build

.PHONY: default lint all flash clean

default: lint all flash clean

lint:
	cpplint --extensions=ino --filter=-legal/copyright,-runtime/int *.ino

all:
	arduino-cli compile --fqbn $(BOARD) --output-dir $(BUILD) ./

flash:
	arduino-cli upload --fqbn $(BOARD) --port $(PORT) --input-dir $(BUILD)

clean:
	rm -r build