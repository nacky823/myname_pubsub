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

+ 新しいターミナルで、以下のコマンドを実行
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
    

© 2023 nacky823