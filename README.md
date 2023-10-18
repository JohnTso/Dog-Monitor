# Smart-Pet
My semester project, build a health monitor device with Arduino Nano 33 BLE sense

* To set up the environment, make sure to run these commands first
```shell
brew install arduino-cli
```

* If you already have arduino-cli, remember to install the following libraries
```shell
arduino-cli core install arduino:mbed
arduino-cli lib install Arduino_LSM9DS1
arduino-cli lib install SD
```
* Remember to also go into the Arduino IDE to install the ```PulseSensor Playground``` and ```Wire```

* If you do not have cpplint installed still, run
```shell
pip3 install cpplint
```

* RFC document
https://docs.google.com/document/d/1kEhEuaUNniLgcGZ6a8SjvLJjtZSAe4iUedIUJRCNQcY/edit?usp=sharing
