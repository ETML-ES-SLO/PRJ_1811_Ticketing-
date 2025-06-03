namespace _1811C_Ticketing
{
    partial class Form2
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form2));
            this.Btn_Configure = new System.Windows.Forms.Button();
            this.BaudRate = new System.Windows.Forms.TextBox();
            this.Port_BaudRate = new System.Windows.Forms.Label();
            this.Port_Parity = new System.Windows.Forms.Label();
            this.Parity = new System.Windows.Forms.ComboBox();
            this.Port_Data_Bits = new System.Windows.Forms.Label();
            this.Data_Bits = new System.Windows.Forms.TextBox();
            this.Port_Stop_Bit = new System.Windows.Forms.Label();
            this.Port_Handshake = new System.Windows.Forms.Label();
            this.Stop_Bits = new System.Windows.Forms.ComboBox();
            this.Handshake = new System.Windows.Forms.ComboBox();
            this.Btn_SLO1 = new System.Windows.Forms.Button();
            this.Btn_SLO2 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Btn_Configure
            // 
            this.Btn_Configure.Font = new System.Drawing.Font("Arial", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Btn_Configure.Location = new System.Drawing.Point(124, 338);
            this.Btn_Configure.Name = "Btn_Configure";
            this.Btn_Configure.Size = new System.Drawing.Size(133, 53);
            this.Btn_Configure.TabIndex = 0;
            this.Btn_Configure.Text = "Configure";
            this.Btn_Configure.UseVisualStyleBackColor = true;
            this.Btn_Configure.Click += new System.EventHandler(this.Btn_Configure_Click);
            // 
            // BaudRate
            // 
            this.BaudRate.Location = new System.Drawing.Point(213, 35);
            this.BaudRate.Name = "BaudRate";
            this.BaudRate.Size = new System.Drawing.Size(100, 20);
            this.BaudRate.TabIndex = 1;
            this.BaudRate.Text = "57600";
            this.BaudRate.TextChanged += new System.EventHandler(this.BaudRate_TextChanged);
            // 
            // Port_BaudRate
            // 
            this.Port_BaudRate.AutoSize = true;
            this.Port_BaudRate.Font = new System.Drawing.Font("Arial", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Port_BaudRate.Location = new System.Drawing.Point(64, 34);
            this.Port_BaudRate.Name = "Port_BaudRate";
            this.Port_BaudRate.Size = new System.Drawing.Size(115, 19);
            this.Port_BaudRate.TabIndex = 2;
            this.Port_BaudRate.Text = "Port BaudRate";
            // 
            // Port_Parity
            // 
            this.Port_Parity.AutoSize = true;
            this.Port_Parity.Font = new System.Drawing.Font("Arial", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Port_Parity.Location = new System.Drawing.Point(64, 90);
            this.Port_Parity.Name = "Port_Parity";
            this.Port_Parity.Size = new System.Drawing.Size(87, 19);
            this.Port_Parity.TabIndex = 3;
            this.Port_Parity.Text = "Port Parity";
            // 
            // Parity
            // 
            this.Parity.FormattingEnabled = true;
            this.Parity.Items.AddRange(new object[] {
            "None",
            "Odd",
            "Even",
            "Mark",
            "Space"});
            this.Parity.Location = new System.Drawing.Point(213, 88);
            this.Parity.Name = "Parity";
            this.Parity.Size = new System.Drawing.Size(100, 21);
            this.Parity.TabIndex = 4;
            this.Parity.Text = "None";
            this.Parity.SelectedIndexChanged += new System.EventHandler(this.Parity_SelectedIndexChanged);
            // 
            // Port_Data_Bits
            // 
            this.Port_Data_Bits.AutoSize = true;
            this.Port_Data_Bits.Font = new System.Drawing.Font("Arial", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Port_Data_Bits.Location = new System.Drawing.Point(64, 152);
            this.Port_Data_Bits.Name = "Port_Data_Bits";
            this.Port_Data_Bits.Size = new System.Drawing.Size(110, 19);
            this.Port_Data_Bits.TabIndex = 5;
            this.Port_Data_Bits.Text = "Port Data Bits";
            // 
            // Data_Bits
            // 
            this.Data_Bits.Location = new System.Drawing.Point(213, 151);
            this.Data_Bits.Name = "Data_Bits";
            this.Data_Bits.Size = new System.Drawing.Size(100, 20);
            this.Data_Bits.TabIndex = 6;
            this.Data_Bits.Text = "8";
            this.Data_Bits.TextChanged += new System.EventHandler(this.Data_Bits_TextChanged);
            // 
            // Port_Stop_Bit
            // 
            this.Port_Stop_Bit.AutoSize = true;
            this.Port_Stop_Bit.Font = new System.Drawing.Font("Arial", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Port_Stop_Bit.Location = new System.Drawing.Point(64, 279);
            this.Port_Stop_Bit.Name = "Port_Stop_Bit";
            this.Port_Stop_Bit.Size = new System.Drawing.Size(109, 19);
            this.Port_Stop_Bit.TabIndex = 7;
            this.Port_Stop_Bit.Text = "Port Stop Bits";
            // 
            // Port_Handshake
            // 
            this.Port_Handshake.AutoSize = true;
            this.Port_Handshake.Font = new System.Drawing.Font("Arial", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Port_Handshake.Location = new System.Drawing.Point(64, 214);
            this.Port_Handshake.Name = "Port_Handshake";
            this.Port_Handshake.Size = new System.Drawing.Size(125, 19);
            this.Port_Handshake.TabIndex = 8;
            this.Port_Handshake.Text = "Port Handshake";
            // 
            // Stop_Bits
            // 
            this.Stop_Bits.FormattingEnabled = true;
            this.Stop_Bits.Items.AddRange(new object[] {
            "None",
            "One",
            "OnePointFive",
            "Two"});
            this.Stop_Bits.Location = new System.Drawing.Point(213, 280);
            this.Stop_Bits.Name = "Stop_Bits";
            this.Stop_Bits.Size = new System.Drawing.Size(100, 21);
            this.Stop_Bits.TabIndex = 9;
            this.Stop_Bits.Text = "One";
            this.Stop_Bits.SelectedIndexChanged += new System.EventHandler(this.Stop_Bits_SelectedIndexChanged);
            // 
            // Handshake
            // 
            this.Handshake.FormattingEnabled = true;
            this.Handshake.Items.AddRange(new object[] {
            "None",
            "RequestToSend",
            "RequestToSendXOnXOff",
            "XOnXOff"});
            this.Handshake.Location = new System.Drawing.Point(213, 212);
            this.Handshake.Name = "Handshake";
            this.Handshake.Size = new System.Drawing.Size(100, 21);
            this.Handshake.TabIndex = 10;
            this.Handshake.Text = "None";
            this.Handshake.SelectedIndexChanged += new System.EventHandler(this.Handshake_SelectedIndexChanged);
            // 
            // Btn_SLO1
            // 
            this.Btn_SLO1.Font = new System.Drawing.Font("Arial", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Btn_SLO1.Location = new System.Drawing.Point(46, 416);
            this.Btn_SLO1.Name = "Btn_SLO1";
            this.Btn_SLO1.Size = new System.Drawing.Size(133, 53);
            this.Btn_SLO1.TabIndex = 11;
            this.Btn_SLO1.Text = "SLO1";
            this.Btn_SLO1.UseVisualStyleBackColor = true;
            this.Btn_SLO1.Click += new System.EventHandler(this.Btn_SLO1_Click);
            // 
            // Btn_SLO2
            // 
            this.Btn_SLO2.Font = new System.Drawing.Font("Arial", 12.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Btn_SLO2.Location = new System.Drawing.Point(213, 416);
            this.Btn_SLO2.Name = "Btn_SLO2";
            this.Btn_SLO2.Size = new System.Drawing.Size(133, 53);
            this.Btn_SLO2.TabIndex = 12;
            this.Btn_SLO2.Text = "SLO2";
            this.Btn_SLO2.UseVisualStyleBackColor = true;
            this.Btn_SLO2.Click += new System.EventHandler(this.Btn_SLO2_Click);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(396, 481);
            this.Controls.Add(this.Btn_SLO2);
            this.Controls.Add(this.Btn_SLO1);
            this.Controls.Add(this.Handshake);
            this.Controls.Add(this.Stop_Bits);
            this.Controls.Add(this.Port_Handshake);
            this.Controls.Add(this.Port_Stop_Bit);
            this.Controls.Add(this.Data_Bits);
            this.Controls.Add(this.Port_Data_Bits);
            this.Controls.Add(this.Parity);
            this.Controls.Add(this.Port_Parity);
            this.Controls.Add(this.Port_BaudRate);
            this.Controls.Add(this.BaudRate);
            this.Controls.Add(this.Btn_Configure);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form2";
            this.Text = "1811C_Ticketing Paramètre";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form2_FormClosing);
            this.Load += new System.EventHandler(this.Form2_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Btn_Configure;
        private System.Windows.Forms.TextBox BaudRate;
        private System.Windows.Forms.Label Port_BaudRate;
        private System.Windows.Forms.Label Port_Parity;
        private System.Windows.Forms.ComboBox Parity;
        private System.Windows.Forms.Label Port_Data_Bits;
        private System.Windows.Forms.TextBox Data_Bits;
        private System.Windows.Forms.Label Port_Stop_Bit;
        private System.Windows.Forms.Label Port_Handshake;
        private System.Windows.Forms.ComboBox Stop_Bits;
        private System.Windows.Forms.ComboBox Handshake;
        private System.Windows.Forms.Button Btn_SLO1;
        private System.Windows.Forms.Button Btn_SLO2;
    }
}