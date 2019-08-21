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
        static void Main()
        {
            // Create Server
            TcpServerChannel channel = new TcpServerChannel(8080);
            ChannelServices.RegisterChannel(channel, false);

            // Register Player
            RemotingConfiguration.RegisterWellKnownServiceType(typeof(Player), "Player", WellKnownObjectMode.SingleCall);

            Console.WriteLine("Listening for requests. \nPress enter to exit...\n");
            Console.ReadLine();
        }
    }
}
