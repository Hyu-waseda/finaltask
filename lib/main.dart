import 'package:finaltask/screens/screen_B.dart';
import 'package:flutter/material.dart';
import 'package:finaltask/screens/screen_A.dart';

void main() {
  runApp(
    const MaterialApp(
      title: "Navigation Basics",
      home: MyApp(),
    ),
  );
}

class MyApp extends StatefulWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  List<Map<String, dynamic>> items = [
    {
      "title": "プログラミングA",
      "month": "1",
      "day": "1",
      "hour": "23",
      "minutes": "59"
    },
    {
      "title": "プログラミングB",
      "month": "2",
      "day": "2",
      "hour": "23",
      "minutes": "59"
    },
    { "title": "数学試験",
      "month": "3",
      "day": "3",
      "hour": "12",
      "minutes": "30"
    }
  ];

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('締め切り管理'),
        ),
        body: ListView.builder(
            itemCount: items.length,
            itemBuilder: (BuildContext context, int index) {
              final item = items[index];
              return Dismissible(
                key: Key(item["title"]),
                direction: DismissDirection.endToStart,
                onDismissed: (direction) {
                  setState(() {
                    items.removeAt(index);
                  });
                  ScaffoldMessenger.of(context).showSnackBar(
                    SnackBar(
                      content: Text("削除しました"),
                    ),
                  );
                },
                background: Container(
                  alignment: Alignment.centerRight,
                  color: Colors.redAccent[200],
                  child: Padding(
                    padding: EdgeInsets.fromLTRB(10.0, 0.0, 20.0, 0.0),
                    child: Icon(Icons.delete, color: Colors.white),
                  ),
                ),
                child: Card(
                  child: ListTile(
                    leading: FlutterLogo(),
                    title: Row(
                      mainAxisAlignment: MainAxisAlignment.spaceBetween,
                      children: [
                        SizedBox(
                          child: Text(item["title"]),
                          width: 170,
                        ),
                        Column(
                          children: [
                            SizedBox(
                              child: Text(item["month"] + "/" + item["day"],
                                  textAlign: TextAlign.right),
                              width: 47,
                            ),
                            SizedBox(
                              child: Text(item["hour"] + ":" + item["minutes"],
                                  textAlign: TextAlign.right),
                              width: 47,
                            ),
                          ],
                        ),
                      ],
                    ),
                    onTap: () async {
                      print("yes");
                      var lst = await Navigator.push(context,
                          MaterialPageRoute(builder: (context) {
                        return ScreenA(item: item);
                      }));
                      setState(() {
                        items[index]["title"] = lst[0];
                        items[index]["month"] = lst[1];
                        items[index]["day"] = lst[2];
                        items[index]["hour"] = lst[3];
                        items[index]["minutes"] = lst[4];
                      });
                    },
                  ),
                ),
              );
            }),

        floatingActionButton: FloatingActionButton(
          tooltip: 'Increment',
          onPressed: () async {
            var newLst = await Navigator.push(context,
                MaterialPageRoute(builder: (context) {
              return ScreenB();
            }));
            setState(() {
              Map<String, dynamic> newItem = {
                "title": newLst[0],
                "month": newLst[1],
                "day": newLst[2],
                "hour": newLst[3],
                "minutes": newLst[4]
              };
              items.add(newItem);
            });
          },
          child: Icon(Icons.add),
        ),
      ),
    );
  }
}
