import java.io.IOException;
import java.util.*;

// import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.fs.*;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.conf.*;
import org.apache.hadoop.io.*;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapred.*;
import org.apache.hadoop.util.*;

public class WordCount {
    
    @Override
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
        
        JobConf conf = new JobConf(WordCount.class);
        FileInputFormat.setInputPaths(conf, new Path(args[0]));
        FileOutputFormat.setOutputPath(conf, new Path(args[1]));

        conf.setJobName("wordcount");
        
        conf.setOutputKeyClass(Text.class);
        conf.setOutputValueClass(IntWritable.class);
        
        conf.setMapperClass(Maperrr.class);
        conf.setCombinerClass(Reducerr.class);
        conf.setReducerClass(Reducerrr.class);
        
        conf.setInputFormat(TextInputFormat.class);
        conf.setOutputFormat(TextOutputFormat.class);
        
        // JobConf jc = new JobConf(WordCount.class);
        // FileInputFormat.setInputPaths(jc, new Path(args[0]));
        // FileOutputFormat.setOutputPath(jc, new Path(args[1]));
        // jc.setMapperClass(WordCountMapper.class);
        // jc.setReducerClass(WordCountReducer.class);
        // jc.setMapOutputKeyClass(Text.class);
        // jc.setMapOutputValueClass(IntWritable.class);
        // jc.setOutputKeyClass(Text.class);
        // jc.setOutputValueClass(IntWritable.class);
        // JobClient.runJob(jc);
        
        
        JobClient.runJob(conf);
        
    }
    
}
