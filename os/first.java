import java.io.*;
import java.nio.channels.FileChannel;

class first{
	public static void main(String args[])  throws IOException{
		File file1 = new File("/home/student/Desktop/os/first.java");
		File file2 = new File("/home/student/Desktop/second.java");
		copyFile(file1,file2);
	}


private static void copyFile(File sourceFile, File destFile)
        throws IOException {
    if (!sourceFile.exists()) {
        return;
    }
    if (!destFile.exists()) {
        destFile.createNewFile();
    }
    FileChannel source = null;
    FileChannel destination = null;
    source = new FileInputStream(sourceFile).getChannel();
    destination = new FileOutputStream(destFile).getChannel();
    if (destination != null && source != null) {
        destination.transferFrom(source, 0, source.size());
    }
    if (source != null) {
        source.close();
    }
    if (destination != null) {
        destination.close();
    }

}
}