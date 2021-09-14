
//申请内存空间
let buffer = new Buffer("../../5G/phy/IQ/iq-in.bin");
let int16array = new Int16Array(buffer);

//打印一下
console.log(int16array.length);
console.log(int16array.byteLength);
console.log(int16array[0]);

//显示buffer信息
let bufferview = new DataView(buffer);
console.log(bufferview);


//TODO:       


