import java.io.*;
import java.net.*;
import java.util.*;


public class socket
{
    
	
   public static void main(String[] args )
   {
      try
      {
	ServerSocket s = new ServerSocket(8189);
      
         Socket incoming = s.accept( );
         
         InputStream inStream = incoming.getInputStream();
         OutputStream outStream = incoming.getOutputStream();

         Scanner in = new Scanner(inStream);
         PrintWriter out = new PrintWriter(outStream, true /* autoFlush */);

         out.println( "Hello! Enter BYE to exit." );

         boolean done = false;
         while (!done && in.hasNextLine())
         {
            String line = in.nextLine();
            out.println("Echo: " + line);
         	Cliente teste;
			if (line.trim().equals("classe"))
         		teste = new Cliente(line);
			teste.
         }
         
      }
      catch (IOException e)
      { e.printStackTrace();} } 
   

   
}

