# ROS 2 Humble myname_pubsub

[![build](https://github.com/nacky823/myname_pubsub/actions/workflows/build_test.yml/badge.svg)](https://github.com/nacky823/myname_pubsub/actions/workflows/build_test.yml)

任意の単語を、任意の周期で publish & subscribe を行う ROS 2 Humble のパッケージです。

## 動作確認済みの環境

+ OS : Ubuntu 22.04.1 LTS
+ Software : ROS 2 Humble

## Input / Output

### Input and Output

| **Name (Topic)** | **Type** | **Description** |
| --- | --- | --- |
| `/name_topic` | `std_msgs::msg::String` | 標準出力する指定した単語 |

### Parameter

| **Name (Parameter)** | **Type** | **Description** |
| --- | --- | --- |
| `pub_name` | `std::string` | 標準出力する任意の単語 |
| `pub_rate` | `double` | 単語を出力する周期 [s] |

## ディレクトリ構成

```
.
├── CMakeLists.txt
├── LICENCE
├── README.md
├── config
│   └── params_myname.param.yaml
├── include
│   └── myname_pubsub
│       └── core.hpp
├── launch
│   └── myname_pubsub_launch.py
├── package.xml
└── src
    ├── core.cpp
    └── node.cpp

5 directories, 9 files
```

## インストール

※ ROS 2 のインストール方法については記述しません。

+ 適切な ROS 2 ワークスペース内でクローン

    ```
    git clone https://github.com/nacky823/myname_pubsub.git
    ```

    > クローン終了後、ビルド＆ソースを行う。

## Backward ROS を用いたデバッグ方法

1. 以下のコマンドを実行
    ```
    ros2 launch myname_pubsub myname_pubsub_launch.py
    ```
    > エラーが発生した場合、ノードが何処で kill されたのかを教えてくれます。

## 使用方法

1. ( 任意 ) config ディレクトリにある params_myname.param.yaml ファイルを編集

    + params_myname.param.yaml

        ```
        /myname_pubsub:
          ros__parameters:
            pub_name: 'packy'
            pub_rate: 1.7
        ```

        > + packy の部分を、任意の単語に設定可能
        > + 1.7 の部分を、任意の周期に設定可能

        このファイルに記述した単語が、記述した周期 [s] で publish & subscribe される。

1. 以下のコマンドを実行

    ```
    ros2 launch myname_pubsub myname_pubsub_launch.py
    ```

    + 実行すると以下のように標準出力される
    ```
    [INFO] [launch]: Default logging verbosity is set to INFO
    [INFO] [name_pubsub_exe-1]: process started with pid [25115]
    [name_pubsub_exe-1] [INFO] [1683289114.874790200] [myname_pubsub]: Initial name is packy.
    [name_pubsub_exe-1] [INFO] [1683289114.875062900] [myname_pubsub]: Initial period is 1.700000[s].
    [name_pubsub_exe-1] [INFO] [1683289116.575399100] [myname_pubsub]: Subscibed : 'packy, count = 0'
    [name_pubsub_exe-1] [INFO] [1683289118.275463400] [myname_pubsub]: Subscibed : 'packy, count = 1'
    ```

    > 指定した単語が、指定した周期で出力される

1. 別の新しいターミナルで、以下のコマンドを実行

    hoge のように任意の単語を指定すると、指定した単語が出力される。 

    ```
    ros2 param set /myname_pubsub pub_name hoge
    ```
    > `Set parameter successful` と出力されれば問題なし

    + 実行すると以下のように標準出力される
    ```
    [INFO] [launch]: Default logging verbosity is set to INFO
    [INFO] [name_pubsub_exe-1]: process started with pid [25115]
    [name_pubsub_exe-1] [INFO] [1683289114.874790200] [myname_pubsub]: Initial name is packy.
    [name_pubsub_exe-1] [INFO] [1683289114.875062900] [myname_pubsub]: Initial period is 1.700000[s].
    [name_pubsub_exe-1] [INFO] [1683289116.575399100] [myname_pubsub]: Subscibed : 'packy, count = 0'
    [name_pubsub_exe-1] [INFO] [1683289118.275463400] [myname_pubsub]: Subscibed : 'packy, count = 1'
    [name_pubsub_exe-1] [INFO] [1683289119.975149900] [myname_pubsub]: Change name to hoge.
    [name_pubsub_exe-1] [INFO] [1683289119.975651500] [myname_pubsub]: Subscibed : 'hoge, count = 2'
    [name_pubsub_exe-1] [INFO] [1683289121.675469100] [myname_pubsub]: Subscibed : 'hoge, count = 3'
    [name_pubsub_exe-1] [INFO] [1683289123.375373700] [myname_pubsub]: Subscibed : 'hoge, count = 4'
    ```

1. 以下のコマンドを実行

    1.0 のように任意の周期を指定すると、指定した周期で単語が出力される。
    ```
    ros2 param set /myname_pubsub pub_rate 1.0
    ```
    > `Set parameter successful` と出力されれば問題なし

    + 実行すると以下のように標準出力される
    ```
    [INFO] [launch]: Default logging verbosity is set to INFO
    [INFO] [name_pubsub_exe-1]: process started with pid [25115]
    [name_pubsub_exe-1] [INFO] [1683289114.874790200] [myname_pubsub]: Initial name is packy.
    [name_pubsub_exe-1] [INFO] [1683289114.875062900] [myname_pubsub]: Initial period is 1.700000[s].
    [name_pubsub_exe-1] [INFO] [1683289116.575399100] [myname_pubsub]: Subscibed : 'packy, count = 0'
    [name_pubsub_exe-1] [INFO] [1683289118.275463400] [myname_pubsub]: Subscibed : 'packy, count = 1'
    [name_pubsub_exe-1] [INFO] [1683289119.975149900] [myname_pubsub]: Change name to hoge.
    [name_pubsub_exe-1] [INFO] [1683289119.975651500] [myname_pubsub]: Subscibed : 'hoge, count = 2'
    [name_pubsub_exe-1] [INFO] [1683289121.675469100] [myname_pubsub]: Subscibed : 'hoge, count = 3'
    [name_pubsub_exe-1] [INFO] [1683289123.375373700] [myname_pubsub]: Subscibed : 'hoge, count = 4'
    [name_pubsub_exe-1] [INFO] [1683289125.075079200] [myname_pubsub]: Changed period to 1.000000[s].
    [name_pubsub_exe-1] [INFO] [1683289125.075652900] [myname_pubsub]: Subscibed : 'hoge, count = 5'
    [name_pubsub_exe-1] [INFO] [1683289126.075585900] [myname_pubsub]: Subscibed : 'hoge, count = 6'
    [name_pubsub_exe-1] [INFO] [1683289127.075839900] [myname_pubsub]: Subscibed : 'hoge, count = 7'
    [name_pubsub_exe-1] [INFO] [1683289128.076095400] [myname_pubsub]: Subscibed : 'hoge, count = 8'
    [name_pubsub_exe-1] [INFO] [1683289129.075822200] [myname_pubsub]: Subscibed : 'Mr.Ikebe, count = 9'
    [name_pubsub_exe-1] [INFO] [1683289130.075787600] [myname_pubsub]: Subscibed : 'hoge, count = 0'
    ```

    > + count が 0 ~ 8 の場合、指定した単語が出力される。
    > + count が 9 の場合、Mr.Ikebe という名前が出力される。ちょっとした遊び心ですね。

    パラメータの変更は何度でも行えます。
    以上がこのパッケージの使用法になります。

## 参考文献

+ https://docs.ros.org/en/humble/index.html
+ https://github.com/uhobeike/ros2_cpp_template

## ライセンス

このソフトウェアパッケージは、Apache License 2.0 のもと、再配布および使用が許可されます。

© 2023 nacky823