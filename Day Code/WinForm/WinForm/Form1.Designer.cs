namespace WinForm
{
    partial class Form1
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
            this.cookieButton = new System.Windows.Forms.Button();
            this.cookieCount = new System.Windows.Forms.Label();
            this.amountSelecter = new System.Windows.Forms.NumericUpDown();
            this.cookieWorker1 = new System.ComponentModel.BackgroundWorker();
            this.worker1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.amountSelecter)).BeginInit();
            this.SuspendLayout();
            // 
            // cookieButton
            // 
            this.cookieButton.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
            this.cookieButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(224)))), ((int)(((byte)(192)))));
            this.cookieButton.Cursor = System.Windows.Forms.Cursors.WaitCursor;
            this.cookieButton.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.cookieButton.Location = new System.Drawing.Point(280, 130);
            this.cookieButton.Name = "cookieButton";
            this.cookieButton.Size = new System.Drawing.Size(261, 170);
            this.cookieButton.TabIndex = 0;
            this.cookieButton.Text = "+1 Cookie";
            this.cookieButton.UseVisualStyleBackColor = false;
            this.cookieButton.UseWaitCursor = true;
            this.cookieButton.Click += new System.EventHandler(this.cookieButton_Click);
            // 
            // cookieCount
            // 
            this.cookieCount.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.cookieCount.Location = new System.Drawing.Point(280, 114);
            this.cookieCount.Name = "cookieCount";
            this.cookieCount.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.cookieCount.Size = new System.Drawing.Size(261, 13);
            this.cookieCount.TabIndex = 1;
            this.cookieCount.Text = "0 Cookies";
            this.cookieCount.TextAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.cookieCount.UseMnemonic = false;
            // 
            // amountSelecter
            // 
            this.amountSelecter.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.amountSelecter.Cursor = System.Windows.Forms.Cursors.WaitCursor;
            this.amountSelecter.Location = new System.Drawing.Point(575, 213);
            this.amountSelecter.Maximum = new decimal(new int[] {
            1316134912,
            2328,
            0,
            0});
            this.amountSelecter.Name = "amountSelecter";
            this.amountSelecter.Size = new System.Drawing.Size(120, 20);
            this.amountSelecter.TabIndex = 2;
            this.amountSelecter.UseWaitCursor = true;
            // 
            // cookieWorker1
            // 
            this.cookieWorker1.DoWork += new System.ComponentModel.DoWorkEventHandler(this.backgroundWorker1_DoWork);
            // 
            // worker1
            // 
            this.worker1.AutoSize = true;
            this.worker1.Location = new System.Drawing.Point(13, 13);
            this.worker1.Name = "worker1";
            this.worker1.Size = new System.Drawing.Size(100, 23);
            this.worker1.TabIndex = 3;
            this.worker1.Text = "+1 Cookie worker";
            this.worker1.UseVisualStyleBackColor = true;
            this.worker1.Click += new System.EventHandler(this.worker1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.worker1);
            this.Controls.Add(this.amountSelecter);
            this.Controls.Add(this.cookieCount);
            this.Controls.Add(this.cookieButton);
            this.Cursor = System.Windows.Forms.Cursors.WaitCursor;
            this.Name = "Form1";
            this.Text = "Form1";
            this.UseWaitCursor = true;
            ((System.ComponentModel.ISupportInitialize)(this.amountSelecter)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button cookieButton;
        private System.Windows.Forms.Label cookieCount;
        private System.Windows.Forms.NumericUpDown amountSelecter;
        private System.ComponentModel.BackgroundWorker cookieWorker1;
        private System.Windows.Forms.Button worker1;
    }
}

