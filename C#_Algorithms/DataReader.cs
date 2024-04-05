
using System;

namespace SendingEmail
{
    public class DataReader
    {
//	private const string fileName = "../Data/Data.txt";
	private const string fileName = "/home/vahe1525/Documents/Vahe_Karmirshalyan/Camera/CapturingMotion/Data/Data.txt";

	public static Data ReadData()
	{
	    //line of the file
	    string email = "";
	    string message = "";
	    
	    //Pass the file path and file name to the StreamReader constructor
	    StreamReader sr = new StreamReader(fileName);

	    email = sr.ReadLine();
	    Console.WriteLine("email = " + email);
	    //message = sr.ReadLine();

	    //Data variable
	    Data data = new Data(email, message);

	    //close the file
	    sr.Close();

	    return data;

	}

    }
}
