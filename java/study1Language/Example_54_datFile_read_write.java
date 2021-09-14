import java.io.DataInput;
import java.io.DataOutput;
import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.io.RandomAccessFile;
import java.util.ArrayList;
import java.util.List;


class Employee{
    public static int RecordSize=72;// 总计8+30*2+4=72字节，算准总字节数对于连续读取很重要
    private long id;// long类型似占8字节
    private String name;
    public static int NameSize=30;// 预计名称最多30个字符，占30*2=60字节
    private int age;// int类型占4字节
    
    public Employee(long id,String name,int age){
        this.id=id;
        this.name=name;
        this.age=age;
    }
    
    public String toString(){
        return "ID="+id+" name:"+name+" age:"+age;
    }
    
    public long getId() {
        return id;
    }
    public void setId(long id) {
        this.id = id;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getAge() {
        return age;
    }
    public void setAge(int age) {
        this.age = age;
    }
}

class Example_54{
    public static void main(String[] args) throws Exception{
        // 准备数据
        List<Employee> ls=new ArrayList<Employee>();
        
        final int AMOUT=10;
        for(long i=0;i<AMOUT;i++){
            ls.add(new Employee(i,"克隆人-"+i,(int)(i %100)));
        }
        
        // 写入
        DataOutputStream out=new DataOutputStream(new FileOutputStream("emp.dat"));
        for(Employee emp:ls){
            writeEmp(out,emp);
        }
        
        // 挨个读取
        RandomAccessFile in=new RandomAccessFile("emp.dat","r");
        int len=(int)(in.length()/Employee.RecordSize);
        
        for(long i=0;i<len;i++){
            in.seek(i*Employee.RecordSize);
            
            Employee emp=readEmp(in);
            System.out.println(emp.toString());
        }
    }
    
    private static void writeEmp(DataOutput out,Employee emp) throws Exception{
        writeString(emp.getName(),Employee.NameSize,out);
        out.writeLong(emp.getId());
        out.writeInt(emp.getAge());
    }
    
    private static Employee readEmp(DataInput in)  throws Exception{
        String name=readString(Employee.NameSize,in);
        long sn=in.readLong();
        int age=in.readInt();
        
        return new Employee(sn,name,age);
    }
    
    // 写入最大长度为size的字符串，不足写0
    private static void writeString(String str,int size,DataOutput out) throws Exception{
        for(int i=0;i<size;i++){
            char c=0;
            if(i<str.length()){
                c=str.charAt(i);
            }
            out.writeChar(c);
        }
    }
    
    // 读入最大长度为size的字符串
    private static String readString(int size,DataInput in) throws Exception{
        StringBuilder sb=new StringBuilder();
        
        for(int i=0;i<size;i++){
            char c=in.readChar();
            
            if(c==0){
                continue;
            }else{
                sb.append(c);
            }
        }
        
        return sb.toString();
    }
}
