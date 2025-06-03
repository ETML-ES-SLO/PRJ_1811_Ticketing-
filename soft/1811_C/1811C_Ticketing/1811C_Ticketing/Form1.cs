using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;
using System.IO;
using System.Windows.Forms;

namespace _1811C_Ticketing
{

    public partial class Form1 : Form
    {

        public static int BaudRate, Data_bits;
        public static string Parity,Handshake, Stop_Bits, CB_Port_Past;
        
        public static bool New_Port = true, Unconnect = false, Start = true, Confirme_Change,Close_Windows;

        public static Form1 frm1 = new Form1();

        public Form1()
        {
            InitializeComponent();

            //transfert des variables de la form2 à la form1
            BaudRate = Form2.BaudRate_Change;
            Parity = Form2.Parity_Change;
            Data_bits = Form2.Data_Bits_Change;
            Handshake = Form2.Handshake_Change;
            Stop_Bits = Form2.Stop_Bits_Change;
            Confirme_Change = Form2.Change;
            Close_Windows = Form2.Windows_Close;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Btn_Acc_Click(object sender, EventArgs e)
        {
            if (Global.Receive_Message == true)
            {
                // preparation du message
                // indicateur de start = AA
                // derniere adresse recu
                // Message, ici c'est "ACCEPT"
                //indicateur de fin = BB
                string envoie = Constants.Start + Global.Actual_Student + Constants.Accept + Constants.End;
                if (AnyClass.port.IsOpen)//Verifier si le port com est ouvert
                {
                    //envoie du message
                    SerialPort.Write(envoie);
                }
                else
                {
                    //Si le port n'est pas ouvert ouverture de fenetre pour indiquer d'en selectionner un
                    MessageBox.Show("Please select a port first and connect it");
                }

                Global.Receive_Message = false;
            }
            
        }

        private void Btn_Dec_Click(object sender, EventArgs e)
        {
            if (Global.Receive_Message == true)
            {
                // preparation du message
                // indicateur de start = AA
                // derniere adresse recu
                // Message, ici c'est "DECLINE"
                //indicateur de fin = CC
                string envoie = Constants.Start + Global.Actual_Student + Constants.Decline + Constants.End;
                if (AnyClass.port.IsOpen)//Verifier si le port com est ouvert
                {
                    //envoie du message
                    SerialPort.Write(envoie);
                }
                else
                {
                    //Si le port n'est pas ouvert ouverture de fenetre pour indiquer d'en selectionner un
                    MessageBox.Show("Please select a port first and connect it");
                }

                Global.Receive_Message = false;
            }
        }

        private void Btn_Rst_Click(object sender, EventArgs e)
        {
            if (Global.Receive_Message == true)
            {
                // preparation du message
                // indicateur de start = AA
                // Adresse de broadcast
                // Message, ici c'est "RESET"
                //indicateur de fin = CC
                string envoie = Constants.Start + Constants.Adress_Broadcast_ES + Constants.Reset + Constants.End;
                if (AnyClass.port.IsOpen)//Verifier si le port com est ouvert
                {
                    //envoie du message
                    SerialPort.Write(envoie);
                }
                else
                {
                    //Si le port n'est pas ouvert ouverture de fenetre pour indiquer d'en selectionner un
                    MessageBox.Show("Please select a port first and connect it");
                }
            }
                         
        }

        private void Btn_Opt_Click(object sender, EventArgs e)
        {
            //si on n'a aucun message à traiter
            if (Global.Receive_Message == false)
            {

                try
                {
                    //on rend visible l'interface 2
                    Form2.frm2.Visible = true;
                    //on rend invisible la premiere interface
                    Hide();
                }
                catch(Exception)
                {
                    Form2 frm2 = new Form2();
                    frm2.Show();
                    Hide();
                }


            }
        }

        private void CB_Port_Click(object sender, EventArgs e)
        {

            //on recois une list de nom de port
            var ports = SerialPort.GetPortNames();
            //on affiche les nom dans la combo box
            CB_Port.DataSource = ports;
        }

        private void CB_Port_SelectedIndexChanged(object sender, EventArgs e)
        {
            //on convertie le nom selectionner en string et on l'affiche 
            CB_Port.Text = CB_Port.SelectedItem.ToString();
            //on verifie si le Texte afficher à été modifier
            if (CB_Port_Past != CB_Port.Text)
            {
                //on met un flag pour deconnecter le port precedent
                Unconnect = true;

                //vérifie si c'est la premiere fois que nous passons 
                if(Start != true)
                    //si ce n'est pas la premiere fois en entre dans la méthode connect
                Connect();

                //on copie la valeur de Texte 
                CB_Port_Past = CB_Port.Text;

                //on reset le flag de deconnection  
                Unconnect = false;
                Start = false;
            }
            //on verifie si c'est on va utiliser un nouveau port
            if (New_Port == true)
            {
                //Si on entre dans cette déclaration cela veut dire que le port est déjà fermer

                //en cree une nouvelle instance
                AnyClass.port = new SerialPort(CB_Port.SelectedItem.ToString());
                //on reset le flag de nouveau port
                New_Port = false;
            }
            

            
        }

        private void Btn_USB_Click(object sender, EventArgs e)
        {
            //on verifie si un port a été selectionner
            if (CB_Port.SelectedIndex > -1)
            {
                //on indique dans une nouvelle fenetre que le port à été electionner
                MessageBox.Show(string.Format("You selected port '{0}'", CB_Port.SelectedItem));
                Connect();
            }
            else
            {
                MessageBox.Show("Please select a port first");
            }
        }

        //class global
        abstract class AnyClass
        {
            //public static SerialPort port = new SerialPort();
            public static SerialPort port;
            
        }
        private void Connect()
        {

            //SerialPort port = new SerialPort(CB_Port.SelectedItem.ToString());
            //AnyClass.port = new SerialPort(CB_Port.SelectedItem.ToString());

            if (Unconnect == true)
            {
                AnyClass.port.Close();
                New_Port = true;
            }
            else
            {
                //on vérifie si le port est ouvert
                if(AnyClass.port.IsOpen)
                    //s'il est ouvert on le ferme par précaution
                    AnyClass.port.Close();

                if(Confirme_Change == true)
                {
                    //modification des parametres de l'UART selon valeur inscrit par l'utilisateur
                    AnyClass.port.BaudRate = BaudRate;
                    AnyClass.port.Parity = (Parity)Enum.Parse(typeof(Parity), Parity);
                    AnyClass.port.DataBits = Data_bits;
                    AnyClass.port.Handshake = (Handshake)Enum.Parse(typeof(Handshake), Handshake);
                    AnyClass.port.StopBits = (StopBits)Enum.Parse(typeof(StopBits), Stop_Bits);
                }
                else
                {
                    //modification des parametres de l'UART selon valeur par default
                    AnyClass.port.BaudRate = Constants.Default_BaudRate;
                    AnyClass.port.Parity = Constants.Default_Parity; 
                    AnyClass.port.DataBits = Constants.Default_DataBits; ;
                    AnyClass.port.Handshake = Constants.Default_Handshake; 
                    AnyClass.port.StopBits = Constants.Default_Stop_Bits; 
                }
            }
                //on ouvre le port
                AnyClass.port.Open();
        }

        private void SerialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
           



            try
            {

                //on copie le message recu 
                Global.All_Messages = SerialPort.ReadLine();
            }
            catch (TimeoutException) { }


            string result = Global.All_Messages.Remove(0, 1);
             result = result.Remove(result.Length - 1);

            if (Global.All_Messages.Contains(Constants.Accept.ToString()))
            {
                result = result.Remove(0, 4);
                if (WaitList.Text.Contains(result))
                {
                    WaitList.ForeColor = Color.Black;
                }

            }
            else if (Global.All_Messages.Contains(Constants.Decline.ToString()))
            {
                result = result.Remove(0, 4);
                WaitList.Items.Remove(result);
            }
            else if (Global.All_Messages.Contains(Constants.Reset.ToString()))
            {
                WaitList.Items.Clear();
            }
            else if (Global.All_Messages.Contains(Constants.Envoi_Ticket.ToString()))
            {
                result = result.Remove(0, 4);

                WaitList.ForeColor = Color.Red;
                WaitList.Items.Add(result);
                Global.Count_Student = WaitList.Items.Count;
                WaitList.ForeColor = Color.Black;
            }
            Global.Actual_Student = result;

            //on met un flag de reception
            bool Receive_Message = true;
            
        }
    }
}