namespace _1811C_Ticketing
{
    partial class Form1
    {
        /// <summary>
        /// Variable nécessaire au concepteur.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Nettoyage des ressources utilisées.
        /// </summary>
        /// <param name="disposing">true si les ressources managées doivent être supprimées ; sinon, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Code généré par le Concepteur Windows Form

        /// <summary>
        /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
        /// le contenu de cette méthode avec l'éditeur de code.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.Btn_Acc = new System.Windows.Forms.Button();
            this.Btn_Dec = new System.Windows.Forms.Button();
            this.Btn_Rst = new System.Windows.Forms.Button();
            this.WaitList = new System.Windows.Forms.ListBox();
            this.Btn_Opt = new System.Windows.Forms.Button();
            this.btn_USB = new System.Windows.Forms.Button();
            this.CB_Port = new System.Windows.Forms.ComboBox();
            this.SerialPort = new System.IO.Ports.SerialPort(this.components);
            this.SuspendLayout();
            // 
            // Btn_Acc
            // 
            this.Btn_Acc.BackColor = System.Drawing.Color.LawnGreen;
            this.Btn_Acc.Cursor = System.Windows.Forms.Cursors.Hand;
            this.Btn_Acc.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Btn_Acc.ForeColor = System.Drawing.SystemColors.ControlText;
            this.Btn_Acc.Location = new System.Drawing.Point(46, 345);
            this.Btn_Acc.Name = "Btn_Acc";
            this.Btn_Acc.Size = new System.Drawing.Size(129, 50);
            this.Btn_Acc.TabIndex = 0;
            this.Btn_Acc.Text = "Accept";
            this.Btn_Acc.UseVisualStyleBackColor = false;
            this.Btn_Acc.Click += new System.EventHandler(this.Btn_Acc_Click);
            // 
            // Btn_Dec
            // 
            this.Btn_Dec.BackColor = System.Drawing.Color.Red;
            this.Btn_Dec.Cursor = System.Windows.Forms.Cursors.Hand;
            this.Btn_Dec.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.Btn_Dec.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Btn_Dec.Location = new System.Drawing.Point(202, 345);
            this.Btn_Dec.Name = "Btn_Dec";
            this.Btn_Dec.Size = new System.Drawing.Size(129, 50);
            this.Btn_Dec.TabIndex = 1;
            this.Btn_Dec.Text = "Decline";
            this.Btn_Dec.UseVisualStyleBackColor = false;
            this.Btn_Dec.Click += new System.EventHandler(this.Btn_Dec_Click);
            // 
            // Btn_Rst
            // 
            this.Btn_Rst.BackColor = System.Drawing.SystemColors.ScrollBar;
            this.Btn_Rst.Cursor = System.Windows.Forms.Cursors.Hand;
            this.Btn_Rst.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Btn_Rst.Location = new System.Drawing.Point(358, 345);
            this.Btn_Rst.Name = "Btn_Rst";
            this.Btn_Rst.Size = new System.Drawing.Size(129, 50);
            this.Btn_Rst.TabIndex = 2;
            this.Btn_Rst.Text = "Reset";
            this.Btn_Rst.UseVisualStyleBackColor = false;
            this.Btn_Rst.Click += new System.EventHandler(this.Btn_Rst_Click);
            // 
            // WaitList
            // 
            this.WaitList.BackColor = System.Drawing.Color.White;
            this.WaitList.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.WaitList.Font = new System.Drawing.Font("Arial", 12.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.WaitList.ForeColor = System.Drawing.SystemColors.WindowText;
            this.WaitList.FormattingEnabled = true;
            this.WaitList.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.WaitList.ItemHeight = 19;
            this.WaitList.Items.AddRange(new object[] {
            "mario dossantos"});
            this.WaitList.Location = new System.Drawing.Point(46, 31);
            this.WaitList.Name = "WaitList";
            this.WaitList.Size = new System.Drawing.Size(597, 249);
            this.WaitList.TabIndex = 3;
            // 
            // Btn_Opt
            // 
            this.Btn_Opt.BackColor = System.Drawing.Color.WhiteSmoke;
            this.Btn_Opt.Cursor = System.Windows.Forms.Cursors.Hand;
            this.Btn_Opt.Font = new System.Drawing.Font("Arial", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Btn_Opt.Location = new System.Drawing.Point(514, 345);
            this.Btn_Opt.Name = "Btn_Opt";
            this.Btn_Opt.Size = new System.Drawing.Size(129, 50);
            this.Btn_Opt.TabIndex = 4;
            this.Btn_Opt.Text = "Option";
            this.Btn_Opt.UseVisualStyleBackColor = false;
            this.Btn_Opt.Click += new System.EventHandler(this.Btn_Opt_Click);
            // 
            // btn_USB
            // 
            this.btn_USB.Font = new System.Drawing.Font("Arial", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btn_USB.Location = new System.Drawing.Point(232, 286);
            this.btn_USB.Name = "btn_USB";
            this.btn_USB.Size = new System.Drawing.Size(99, 43);
            this.btn_USB.TabIndex = 5;
            this.btn_USB.Text = "Connect";
            this.btn_USB.UseVisualStyleBackColor = true;
            this.btn_USB.Click += new System.EventHandler(this.Btn_USB_Click);
            // 
            // CB_Port
            // 
            this.CB_Port.FormattingEnabled = true;
            this.CB_Port.Location = new System.Drawing.Point(358, 299);
            this.CB_Port.Name = "CB_Port";
            this.CB_Port.Size = new System.Drawing.Size(141, 22);
            this.CB_Port.TabIndex = 6;
            this.CB_Port.SelectedIndexChanged += new System.EventHandler(this.CB_Port_SelectedIndexChanged);
            this.CB_Port.Click += new System.EventHandler(this.CB_Port_Click);
            // 
            // SerialPort
            // 
            this.SerialPort.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.SerialPort_DataReceived);
            // 
            // Form1
            // 
            this.AcceptButton = this.Btn_Acc;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 14F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.CancelButton = this.Btn_Dec;
            this.ClientSize = new System.Drawing.Size(668, 419);
            this.Controls.Add(this.CB_Port);
            this.Controls.Add(this.btn_USB);
            this.Controls.Add(this.WaitList);
            this.Controls.Add(this.Btn_Opt);
            this.Controls.Add(this.Btn_Rst);
            this.Controls.Add(this.Btn_Dec);
            this.Controls.Add(this.Btn_Acc);
            this.Cursor = System.Windows.Forms.Cursors.Default;
            this.Font = new System.Drawing.Font("Arial", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.ShowIcon = false;
            this.Text = "1811C_Ticketing";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button Btn_Acc;
        private System.Windows.Forms.Button Btn_Dec;
        private System.Windows.Forms.Button Btn_Rst;
        private System.Windows.Forms.ListBox WaitList;
        private System.Windows.Forms.Button Btn_Opt;
        private System.Windows.Forms.Button btn_USB;
        private System.Windows.Forms.ComboBox CB_Port;
        private System.IO.Ports.SerialPort SerialPort;
    }
}

