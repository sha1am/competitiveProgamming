// import src.*;
import java.io.IOException;
import java.util.*;

import org.apache.hadoop.fs.*;
import org.apache.hadoop.conf.*;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapred.*;
import org.apache.hadoop.util.*;

public class Maperrr extends MapReduceBase implements Mapper<LongWritable,Text,Text,IntWritable>{
    @Overrride
    public void map(LongWritable key , Text value, OutputCollector<Text,IntWritable> output , Reporter reporter) throws IOException{
        String line= value.toString();
        int arr[]= line.split(" ");
        for(int i=0;i<arr.length;i++){
            if(arr.length()>0){
                output.collect(new Text(arr[i]), new IntWritable(1));
            }
        }
        
    }
}
