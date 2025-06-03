using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Collections;
using System.Collections.Generic;
using System.IO.Ports;

namespace _1811C_Ticketing
{
    public partial class Form2 : Form
    {
        public static int BaudRate_Receive, BaudRate_Change, Data_Bits_Receive, Data_Bits_Change;
        public static string Parity_Receive, Parity_Change, Handshake_Receive, Handshake_Change, Stop_Bits_Change, Stop_Bits_Receive;
        public static bool Change = false, Windows_Close;
        public static Form2 frm2 = new Form2();

        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void Form2_FormClosing(object sender, FormClosingEventArgs e)
        {
            Windows_Close = true;
            Hide();
            Form1.frm1.Visible = true;
        }

        private void BaudRate_TextChanged(object sender, EventArgs e)
        {

            BaudRate_Receive= int.Parse(BaudRate.Text);
            Change = true;
        }

        private void Parity_SelectedIndexChanged(object sender, EventArgs e)
        {
            Parity_Receive = Parity.Text;
            Change = true;
        }

        private void Data_Bits_TextChanged(object sender, EventArgs e)
        {
            Data_Bits_Receive = int.Parse(Data_Bits.Text);
            Change = true;
        }

        private void Handshake_SelectedIndexChanged(object sender, EventArgs e)
        {
            Handshake_Receive = Handshake.Text;
            Change = true;
        }

        private void Stop_Bits_SelectedIndexChanged(object sender, EventArgs e)
        {
            Stop_Bits_Receive = Stop_Bits.Text;
            Change = true;
        }

        private void Btn_Configure_Click(object sender, EventArgs e)
        {
            BaudRate_Change = BaudRate_Receive;
            Parity_Change = Parity_Receive;
            Data_Bits_Change = Data_Bits_Receive;
            Handshake_Change = Handshake_Receive;
            Stop_Bits_Change = Stop_Bits_Receive;
            Hide();
            Form1.frm1.Visible = true;
            frm2.Visible = false;
        }

        private void Btn_SLO1_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("https://gesteleves.etmlnet.local/class/SLO1");
        }

        private void Btn_SLO2_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("https://gesteleves.etmlnet.local/class/SLO2");
        }
    }
}