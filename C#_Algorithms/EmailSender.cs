
using System;
using System.Net;
using System.Net.Mail;

namespace SendingEmail
{
    public class EmailSender
    {
	//private members
	private	string senderEmail = "codecoding42@gmail.com";
	private	string senderPassword = "xgqt utan jgeh tpob";
	
	private void  SendEmail(string recipientEmail, string body = "Security program fixed a motion", string subject = "Security Alert", string smtpServer = "smtp.gmail.com", int port = 587)
	{
            // Create SMTP client
            using (var client = new SmtpClient(smtpServer, port))
            {
                client.UseDefaultCredentials = false;
                client.Credentials = new NetworkCredential(senderEmail, senderPassword);
                client.EnableSsl = true; // Use SSL/TLS

                // Create and send the email
                using (var message = new MailMessage(senderEmail, recipientEmail, subject, body))
                {
                    try
                    {
                        client.Send(message);
                        Console.WriteLine("Email sent successfully!");
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine("Failed to send email: " + ex.Message);
                    }
                }
            }
	    
	}

	public void Send(Data data)
	{
	    //calling private message
	    SendEmail(data.userEmail);
	}
    }
}
