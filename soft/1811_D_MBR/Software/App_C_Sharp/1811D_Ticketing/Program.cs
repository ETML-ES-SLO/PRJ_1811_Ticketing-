using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.IO.Ports;
using System.Threading;
using System.Windows.Forms;


namespace _1811C_Ticketing
{
    public static class Global
    {
        public static string All_Messages;//reception du message complet
        public static bool Receive_Message = false;//vérification si un message a ete recu
        public static string[] List_Name_student = new string[25];//nom des eleves enregistrer
        public static string[] List_Adress = new string[25];//adresse recu

        public static char[] Name_student;//nom des eleves enregistrer
        public static char[] Adress = new char[20];//adresse recu

        public static int Nbr_Student_Save = 0;//Nombre de nom d eleve different
        public static int Nbr_Adress_Save = 0;//Nombre d adresse different

        public static string Actual_Adress;//derniere adresse recu
        public static string Actual_Student;

        public static int Count_Student;
        public static bool Student_OK = false;//vérification si un message a ete recu

        public static int Last_Adress;
    }
    static class Constants
    {
        public const string Start = "AA",  End = "BB";
        public const int Size_Indicator = 2;
        public const int Size_Adress = 6; // 4 pour le Xbee XB24CAPIT-001 ou  16 selon mode utiliser
        public const int Size_Adress_Broadcast = 8;// 4 pour le Xbee XB24CAPIT-001 et 8 pour le broadcast du xbee de l es
        public const string Adress_Broadcast_ES = "00000000";//adresse de broadcast du xbee de l es
        public const string Adress_Broadcast_Xbee4 = "FFFF";//adresse de broadcast du xbee XB24CAPIT-001
        public const string Adress_Broadcast_Xbee16 = "000000000000FFFF";//adresse de broadcast du xbee XB24CAPIT-001
        //public const string Accept = " àÑ5", Decline = "Åû1@", Reset = "°¿àü",Envoi_Ticket = '';// constant des reponses à envoyer
        public const UInt32 Accept = 0x00e0d135, Decline = 0xc5fb3140, Reset = 0xb0bfe0fc,Envoi_Ticket = 0x917283bd;// constant des reponses à envoyer


        public const int Default_BaudRate = 57600;// valeur de default du BaudRate de la communication serial
        public const System.IO.Ports.Parity Default_Parity = System.IO.Ports.Parity.None;// valeur de default de la Partiy de la communication serial
        public const int Default_DataBits = 8;// valeur de default du nombre de bytes de la communication serial
        public const System.IO.Ports.Handshake Default_Handshake = System.IO.Ports.Handshake.None;// valeur de default du handshake de la communication serial
        public const System.IO.Ports.StopBits Default_Stop_Bits = System.IO.Ports.StopBits.One;// valeur de default de la taille du stop bits de la communication serial

    }
    static class Program
    {
        /// <summary>
        /// Point d'entrée principal de l'application.
        /// </summary>


        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());

            if (Global.Receive_Message == true)// on verifie que l'on a bien receptionner un message

            {
                char[] Message = new char[Global.All_Messages.Length];
                int i = 0, compt = 0;

                for (i = 0; i < Global.All_Messages.Length; i++)
                {
                    Message[i] = Global.All_Messages[i]; //copier le string dans un tableau de char
                }
                if (Message[0] == 'A' && Message[1] == 'A')// on verifie si le debut de la trame recu correspond à l'indicateur Start_First = AA
                {
                    do
                    {
                        Global.Adress[compt] = Message[compt + Constants.Size_Indicator]; //copier l'adresse dans un tableau de char (en ignorant les 2 premier caracteres qui sont l'indicateur d envoie)
                        compt++; //indicateur de la position du curseur

                    } while (compt != Constants.Size_Adress + Constants.Size_Indicator); // tant que l'on atteint pas 8 continuer la boucle (2 caracteres pour indicateur + 6 de l adresse)
                    compt = 0;// on reinitialise la position du curseur
                    string Adress = new string(Global.Adress);// on copie le tableau de caratere dans une variable string 


                    for (i = 0; i < Global.List_Adress.Length; i++)// on fait une boucle de la taille du tableau liste d adresse
                    {
                        if (Global.List_Adress[i] != Adress)//On verifie s'il existe
                            Global.List_Adress[Global.Nbr_Adress_Save] = Adress; // on copie l adresse dans le tableau de string liste d adresse
                    }
                    Global.Actual_Adress = Adress;


                    for (i = Adress.Length + Constants.Size_Indicator; i < Global.All_Messages.Length - Adress.Length - 2 * Constants.Size_Indicator; i++)// faire la boucle (taille max du message total moins la taille de l adress et des indicateur de début et de fin)
                    {
                        Global.Name_student[i] = Message[i + Adress.Length + Constants.Size_Indicator];//copie du nom de l eleve du message totale dans un tableau de char
                    }

                    string Name_Student = new string(Global.Name_student);//on copie le tableau de caratere dans une variable string 
                    Global.Nbr_Student_Save++;
                    Global.List_Name_student[Global.Nbr_Student_Save] = Name_Student;// on copie le nom de l eleve dans le tableau de string liste de nom d eleve
                    Global.Actual_Student = Name_Student;
                }
                /*else if (Message[0] == 'B' && Message[1] == 'B')// on verifie si le debut de la trame recu correspond à l'indicateur Start = BB
                {
                    do
                    {
                        Global.Adress[compt] = Message[compt + Constants.Size_Indicator]; //copier l'adresse dans un tableau de char (en ignorant les 2 premier caracteres qui sont l'indicateur d envoie)
                        compt++; //indicateur de la position du curseur

                    } while (compt != Constants.Size_Adress + Constants.Size_Indicator); // tant que l'on atteint pas 8 continuer la boucle (2 caracteres pour indicateur + 6 de l adresse)
                    compt = 0;// on reinitialise la position du curseur
                    string Adress = new string(Global.Adress);// on copie le tableau de caratere dans une variable string 
                    Global.Actual_Adress = Adress;
                    while(Global.Student_OK == true)
                    {
                        if(string.Equals(Global.List_Adress[compt] , Adress))
                        {
                            Global.Student_OK = true;

                            Global.Actual_Student = Global.List_Name_student[compt];
                        }
                        else
                        {
                            compt++;
                        }
                    }
                    compt = 0;

                }*/
            }
        }
    }
}
