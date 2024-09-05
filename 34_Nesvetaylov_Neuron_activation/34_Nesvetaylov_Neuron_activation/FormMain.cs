using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _34_Nesvetaylov_Neuron_activation
{
    public partial class FormMain : Form
    {
        private double[] _pixels = new double[15] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        private void ChangeState(Button b, int index)
        {
            if (b.BackColor == Color.Black)
            {
                b.BackColor = Color.White;
                _pixels[index]= 1d;
            }
            else
            {
                if (b.BackColor == Color.White)
                {
                    b.BackColor = Color.Black;
                    _pixels[index] = 0d;
                }
            }
        }
        public FormMain()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            ChangeState(button2, 0);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ChangeState(button1, 0);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            ChangeState(button4, 0);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            ChangeState(button3, 0);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            ChangeState(button5, 0);
        }
    }
}
