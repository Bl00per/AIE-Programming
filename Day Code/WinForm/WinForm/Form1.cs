using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Timers;

namespace WinForm
{
    public partial class Form1 : Form
    {
        UInt64 amountOfCookies = 0;
        UInt64 cookieWorkers = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void cookieButton_Click(object sender, EventArgs e)
        {
            amountOfCookies++;

            amountOfCookies += (UInt64)amountSelecter.Value;

            //cookieCount.Text = amountOfCookies + " Cookies";
        }

        private void testLabel_Click(object sender, EventArgs e)
        {

        }

        private void backgroundWorker1_DoWork(object sender, DoWorkEventArgs e)
        {
            System.Timers.Timer aTimer = new System.Timers.Timer();
            aTimer.Interval = 1000;

            

            //if ( == "1.0")
        }

        private void worker1_Click(object sender, EventArgs e)
        {
            cookieWorkers += 1;
        }
    }
}
