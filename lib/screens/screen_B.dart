import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

class ScreenB extends StatefulWidget {
  const ScreenB({Key? key}) : super(key: key);

  @override
  _ScreenBState createState() => _ScreenBState();
}

class _ScreenBState extends State<ScreenB> {
  String _title = "???";
  String _month = "?";
  String _day = "?";
  String _hour = "?";
  String _minutes = "?";

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: Text("追加"),
        ),
        body: Column(
          children: [
            SizedBox(height: 40),
            Text("タイトル"),
            Padding(
              padding: const EdgeInsets.all(20.0),
              child: TextField(
                decoration: InputDecoration(
                  hintText: "ここにタイトルを入力してください",
                ),
                onChanged: (value) {
                  setState(() {
                    _title = value;
                  });
                },
              ),
            ),
            SizedBox(height: 40),
            Text("日付"),
            Padding(
              padding: const EdgeInsets.all(20.0),
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                SizedBox(
                  width: 50,
                  child: TextField(
                    inputFormatters: [
                      LengthLimitingTextInputFormatter(2),
                    ],
                    onChanged: (value) {
                      setState(() {
                        _month = value;
                      });
                    },
                  ),
                ),
                Text("月"),
                SizedBox(
                  width: 50,
                  child: TextField(
                    inputFormatters: [
                      LengthLimitingTextInputFormatter(2),
                    ],
                    onChanged: (value) {
                      setState(() {
                        _day = value;
                      });
                    },
                  ),
                ),
                Text("日"),
                SizedBox(
                  width: 50,
                  child: TextField(
                    inputFormatters: [
                      LengthLimitingTextInputFormatter(2),
                    ],
                    onChanged: (value) {
                      setState(() {
                        _hour = value;
                      });
                    },
                  ),
                ),
                Text("時"),
                SizedBox(
                  width: 50,
                  child: TextField(
                    inputFormatters: [
                      LengthLimitingTextInputFormatter(2),
                    ],
                    /*decoration: InputDecoration(
                      hintText: "分",
                    ),*/
                    onChanged: (value) {
                      setState(() {
                        _minutes = value;
                      });
                    },
                  ),
                ),
                Text("分"),
              ],
            ),
            ElevatedButton(
              onPressed: () {
                var lst = [_title, _month, _day, _hour, _minutes];
                Navigator.pop(context, lst);
              },
              child: Text("決定"),
            ),
          ],
        ));
  }
}
