### 課題１ 名前を 0.5 秒ごとに publish & subscribee する

+ 以下のように、ターミナルにコマンドを入力する
    ```
    ros2 run theme1 name_pubsub
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


© 2023 nacky823