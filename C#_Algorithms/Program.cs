
using System;
using System.Net;
using System.Net.Mail;

namespace SendingEmail
{
    public record Data(string userEmail, string message);

    class Program
    {
        static void Main()
        {
	    //Reading data sent from c++
	    Data data = DataReader.ReadData();

	    //Sending Email
	    EmailSender emailsender = new EmailSender();
	    emailsender.Send(data);
	    
        }
    }

}
