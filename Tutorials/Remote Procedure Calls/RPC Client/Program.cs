using System;
using System.Runtime.Remoting;
using System.Runtime.Remoting.Channels.Tcp;
using System.Runtime.Remoting.Channels;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RPC
{
    class Program
    {
        static int port = 8080;
        static string playerName = "Player";

        static void Main()
        {
            // Create Client
            TcpClientChannel channel = new TcpClientChannel();
            ChannelServices.RegisterChannel(channel, false);

            // Get a reference to the player on the server
            string playerURL = "tcp://localhost:" + port + "/" + playerName;
            Player player = (Player)Activator.GetObject(typeof(Player), playerURL);

            while (true)
            {
                Console.Write("Type a message to the server or type 'quit' to exit\n");
                string text = Console.ReadLine();

                if (text == "quit")
                    break;

                // RPC: Call function on server
                player.SayHello(text);
            }
        }
    }
}
