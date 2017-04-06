using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
       
namespace ArduinoAntifurto
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public const string password = "123456789";
        public int i = 0;
        public string messaggio;

        private void button1_Click(object sender, EventArgs e)
        {
            serialPort1.Open();
            if (serialPort1.IsOpen)
            {
                serialPort1.WriteLine("A");
                pictureBox1.BackColor = System.Drawing.Color.Green;
                label1.BackColor = System.Drawing.Color.Green;
                label1.Text = "Active";

            }
            serialPort1.Close();

        }

        private void button2_Click(object sender, EventArgs e)
        {
            
            if (textBox1.Text == password)
            {
                serialPort1.Open();
                if (serialPort1.IsOpen)
                {
                    serialPort1.WriteLine("a");
                    pictureBox1.BackColor = System.Drawing.Color.Red;
                    textBox1.Text = "";
                    label1.BackColor = System.Drawing.Color.Red;
                    label1.Text = "Inactive";

                }
                serialPort1.Close();
            }
            else
            {
                if (i < 3)
                {
                    MessageBox.Show("Wrong Password", "Access Denied", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    i++;
                }
                else
                {
                    serialPort1.Open();
                    if (serialPort1.IsOpen)
                    {
                        serialPort1.WriteLine("B");
                        MessageBox.Show("Wrong Password too many time", "ALERT !!", MessageBoxButtons.OK, MessageBoxIcon.Error);

                    }
                    serialPort1.Close();
                }
                  
            }
                
        }

        private void Form1_Load(object sender, EventArgs e)
        {


        }

        private void timer1_Tick(object sender, EventArgs e)
        {

        }
    }
}
