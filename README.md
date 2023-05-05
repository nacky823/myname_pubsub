# 自律移動チーム ROS2 課題

## 動作確認済みの環境

+ OS : Ubuntu 22.04.1 LTS
+ Software : ROS2 humble

## インストール

※ ROS2 のインストール方法については記述しません。

+ 以下のコマンドをターミナルに入力

    ```
    cd ~/ros2_ws/src/
    ```
    ```
    git clone https://github.com/nacky823/myname_pubsub.git
    ```

    > クローン終了後、ビルド＆ソースを行う。

## 使用方法

### 課題１ 名前を 0.5 秒ごとに publish & subscribee する

+ 以下のコマンドを実行
    ```
    ros2 run myname_pubsub name_pubsub
    ```

+ コマンドの実行結果
    ```
    [INFO] [1683094061.289374500] [listener_comp]: Subscibed : 'nacky, count = 0'
    [INFO] [1683094061.788837000] [listener_comp]: Subscibed : 'nacky, count = 1'
    [INFO] [1683094062.288966100] [listener_comp]: Subscibed : 'nacky, count = 2'
    [INFO] [1683094062.788508800] [listener_comp]: Subscibed : 'nacky, count = 3'
    [INFO] [1683094063.288766800] [listener_comp]: Subscibed : 'nacky, count = 4'
    [INFO] [1683094063.788509100] [listener_comp]: Subscibed : 'nacky, count = 5'
    [INFO] [1683094064.288513200] [listener_comp]: Subscibed : 'nacky, count = 6'
    [INFO] [1683094064.788954100] [listener_comp]: Subscibed : 'nacky, count = 7'
    [INFO] [1683094065.288927900] [listener_comp]: Subscibed : 'nacky, count = 8'
    [INFO] [1683094065.788582000] [listener_comp]: Subscibed : 'Mr.Ikebe, count = 9'
    ```

    > count が 0 ~ 8 の場合、nacky という名前が出力され、
    count が 9 の場合、Mr.Ikebe という名前が出力される。

### 課題２ patameter を変更して、出力周期を変える

+ 以下のコマンドを実行
    ```
    ros2 run myname_pubsub name_pubsub
    ```

+ 別の新しいターミナルで、以下のコマンドを実行
    ```
    ros2 param set /myname_pubsub pub_rate 1.0
    ```

    > `Set parameter successful` と出力されれば問題なし

+ コマンドの実行結果
    ```
    [INFO] [1683125591.201715600] [talker_comp]: Initial period is 2.000000[s].
    [INFO] [1683125593.202511400] [listener_comp]: Subscibed : 'nacky, count = 0'
    [INFO] [1683125595.202095700] [listener_comp]: Subscibed : 'nacky, count = 1'
    [INFO] [1683125597.202083900] [talker_comp]: Changed period to 0.500000[s].
    [INFO] [1683125597.203017100] [listener_comp]: Subscibed : 'nacky, count = 2'
    [INFO] [1683125597.702726800] [listener_comp]: Subscibed : 'nacky, count = 3'
    [INFO] [1683125598.202928900] [listener_comp]: Subscibed : 'nacky, count = 4'
    [INFO] [1683125598.703279100] [listener_comp]: Subscibed : 'nacky, count = 5'
    [INFO] [1683125599.202863300] [listener_comp]: Subscibed : 'nacky, count = 6'
    [INFO] [1683125599.703237000] [listener_comp]: Subscibed : 'nacky, count = 7'
    [INFO] [1683125600.203118300] [listener_comp]: Subscibed : 'nacky, count = 8'
    [INFO] [1683125600.702847400] [listener_comp]: Subscibed : 'Mr.Ikebe, count = 9'
    [INFO] [1683125601.203122600] [listener_comp]: Subscibed : 'nacky, count = 0'
    [INFO] [1683125601.702900100] [listener_comp]: Subscibed : 'nacky, count = 1'
    [INFO] [1683125602.202714300] [talker_comp]: Changed period to 1.000000[s].
    [INFO] [1683125602.202973600] [listener_comp]: Subscibed : 'nacky, count = 2'
    [INFO] [1683125603.203705500] [listener_comp]: Subscibed : 'nacky, count = 3'
    ```

    > `pub_rate` を変更するたび、出力周期が変化する

### 課題３ python の launch ファイルで立ち上げる

+ 以下のコマンドを実行
    ```
    ros2 launch myname_pubsub myname_pubsub_launch.py
    ```

+ 別の新しいターミナルで、以下のコマンドを実行
    ```
    ros2 param set /myname_pubsub pub_rate 0.5
    ```

    > `Set parameter successful` と出力されれば問題なし

+ コマンドの実行結果
    ```
    [INFO] [launch]: Default logging verbosity is set to INFO
    [INFO] [talker-1]: process started with pid [11532]
    [INFO] [listener-2]: process started with pid [11534]
    [talker-1] [INFO] [1683148382.162479400] [talker_launch]: Initial period is 2.000000[s].
    [listener-2] [INFO] [1683148384.163015400] [listener_launch]: Subscibed : 'nacky, count = 0'
    [listener-2] [INFO] [1683148386.163932500] [listener_launch]: Subscibed : 'nacky, count = 1'
    [listener-2] [INFO] [1683148388.162914400] [listener_launch]: Subscibed : 'nacky, count = 2'
    [listener-2] [INFO] [1683148390.163056800] [listener_launch]: Subscibed : 'nacky, count = 3'
    [talker-1] [INFO] [1683148392.162621300] [talker_launch]: Changed period to 0.500000[s].
    [listener-2] [INFO] [1683148392.162983800] [listener_launch]: Subscibed : 'nacky, count = 4'
    [listener-2] [INFO] [1683148392.664134700] [listener_launch]: Subscibed : 'nacky, count = 5'
    [listener-2] [INFO] [1683148393.163397700] [listener_launch]: Subscibed : 'nacky, count = 6'
    [listener-2] [INFO] [1683148393.663409800] [listener_launch]: Subscibed : 'nacky, count = 7'
    [listener-2] [INFO] [1683148394.163168200] [listener_launch]: Subscibed : 'nacky, count = 8'
    [listener-2] [INFO] [1683148394.663101900] [listener_launch]: Subscibed : 'Mr.Ikebe, count = 9'
    [listener-2] [INFO] [1683148395.163944300] [listener_launch]: Subscibed : 'nacky, count = 0'
    ```

    > `pub_rate` を変更するたび、出力周期が変化する

### 課題４ yaml ファイルからパラメータを受け取り、launch.py を起動

+ ( 任意 ) config ディレクトリの params_myname.param.yaml の pub_rate を任意の秒数に書き換える

    ```
    /myname_pubsub:
      ros__parameters:
        pub_name: 'myname_pubsub'
        pub_rate: 1.7
    ```

    > Default では、1.7[s] に設定してあるため、任意の秒数に設定

+ 以下のコマンドを実行

    ```
    ros2 launch myname_pubsub myname_pubsub_launch.py
    ```

+ コマンドの実行結果
    ```
    [INFO] [launch]: Default logging verbosity is set to INFO
    [INFO] [name_pubsub_exe-1]: process started with pid [16943]
    [name_pubsub_exe-1] [INFO] [1683283350.529082900] [myname_pubsub]: Initial period is 1.700000[s].
    [name_pubsub_exe-1] [INFO] [1683283352.229555500] [myname_pubsub]: Subscibed : 'nacky, count = 0'
    [name_pubsub_exe-1] [INFO] [1683283353.929582200] [myname_pubsub]: Subscibed : 'nacky, count = 1'
    [name_pubsub_exe-1] [INFO] [1683283355.629608700] [myname_pubsub]: Subscibed : 'nacky, count = 2'
    [name_pubsub_exe-1] [INFO] [1683283357.329556800] [myname_pubsub]: Subscibed : 'nacky, count = 3'
    [name_pubsub_exe-1] [INFO] [1683283359.030000200] [myname_pubsub]: Subscibed : 'nacky, count = 4'
    [name_pubsub_exe-1] [INFO] [1683283360.729286800] [myname_pubsub]: Changed period to 0.500000[s].
    [name_pubsub_exe-1] [INFO] [1683283360.729491100] [myname_pubsub]: Subscibed : 'nacky, count = 5'
    [name_pubsub_exe-1] [INFO] [1683283361.229874900] [myname_pubsub]: Subscibed : 'nacky, count = 6'
    [name_pubsub_exe-1] [INFO] [1683283361.729778900] [myname_pubsub]: Subscibed : 'nacky, count = 7'
    [name_pubsub_exe-1] [INFO] [1683283362.229754000] [myname_pubsub]: Subscibed : 'nacky, count = 8'
    [name_pubsub_exe-1] [INFO] [1683283362.729974200] [myname_pubsub]: Subscibed : 'Mr.Ikebe, count = 9'
    ```
    

© 2023 nacky823