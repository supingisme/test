
javac Demo_03_JButton_JPanel.java

javah -jni Demo

gcc -shared -fpic -o  libGTK.so -I$JAVA_HOME/include -I$JAVA_HOME/include/linux 37_drawingPic3.c  `pkg-config --cflags --libs gtk+-2.0`


java -Djava.library.path=. Demo
