import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

class ScreenA extends StatefulWidget {
  final item;

  const ScreenA({Key? key, this.item}) : super(key: key);

  @override
  _ScreenAState createState() => _ScreenAState(item);
}

class _ScreenAState extends State<ScreenA> {
  String _inputTitle = "???";
  String _month = "?";
  String _day = "?";
  String _hour = "?";
  String _minutes = "?";
  late DateTime selectedDate;
  final item;

  _ScreenAState(this.item);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: Text("変更"),
        ),
        body: Column(
          children: [
            SizedBox(height: 40),
            Text("タイトル"),
            Padding(
              padding: const EdgeInsets.all(20.0),
              child: TextField(
                decoration: InputDecoration(
                  hintText: item["title"],
                ),
                onChanged: (value) {
                  setState(() {
                    _inputTitle = value;
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
                    decoration: InputDecoration(
                      hintText: item["month"],
                    ),
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
                    decoration: InputDecoration(
                      fillColor: Colors.green,
                      hintText: item["day"],
                    ),
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
                    decoration: InputDecoration(
                      hintText: item["hour"],
                    ),
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
                    //controller: TextEditingController(text: item["minutes"]),
                    inputFormatters: [
                      LengthLimitingTextInputFormatter(2),
                    ],

                    decoration: InputDecoration(
                      hintText: item["minutes"],
                    ),
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
                var lst = [_inputTitle, _month, _day, _hour, _minutes];
                Navigator.pop(context, lst);
              },
              child: Text("決定"),
            ),
          ],
        ));
  }
}
