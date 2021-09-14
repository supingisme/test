//更新的JDK7例如，使用新的“尝试资源关闭”的方法来轻松处理文件。
//package com.yiibai.io;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

class Example_54 {
 public static void main(String[] args) {

  File file = new File("newfile.txt");
  String content = "This is the text content";

  try (FileOutputStream fop = new FileOutputStream(file)) {

   // if file doesn't exists, then create it
   if (!file.exists()) {
    file.createNewFile();
   }

   // get the content in bytes
   byte[] contentInBytes = content.getBytes();

   fop.write(contentInBytes);
   fop.flush();
   fop.close();

   System.out.println("Done");

  } catch (IOException e) {
   e.printStackTrace();
  }
 }
}


