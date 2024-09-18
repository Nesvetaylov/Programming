﻿using System;
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

        private void button1_Click(object sender, EventArgs e)
        {
            ChangeState(button1, 0);
        }
        private void button2_Click(object sender, EventArgs e)
        {
            ChangeState(button2, 0);
        }
        private void button3_Click(object sender, EventArgs e)
        {
            ChangeState(button3, 0);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            ChangeState(button4, 0);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            ChangeState(button5, 0);
        }



        private void FormMain_Load(object sender, EventArgs e)
        {

        }

        private void button6_Click(object sender, EventArgs e)
        {
            ChangeState(button6, 0);
        }

        private void button7_Click(object sender, EventArgs e)
        {
            ChangeState(button7, 0);
        }

        private void button8_Click(object sender, EventArgs e)
        {
            ChangeState(button8, 0);
        }

        private void button9_Click(object sender, EventArgs e)
        {
            ChangeState(button9, 0);
        }

        private void button10_Click(object sender, EventArgs e)
        {
            ChangeState(button10, 0);
        }

        private void button11_Click(object sender, EventArgs e)
        {
            ChangeState(button11, 0);
        }

        private void button12_Click(object sender, EventArgs e)
        {
            ChangeState(button12, 0);
        }

        private void button13_Click(object sender, EventArgs e)
        {
            ChangeState(button13, 0);
        }

        private void button14_Click(object sender, EventArgs e)
        {
            ChangeState(button14, 0);
        }

        private void button15_Click(object sender, EventArgs e)
        {
            ChangeState(button15, 0);
        }



        private void button16_Click(object sender, EventArgs e)
        {

        }

        private void button17_Click(object sender, EventArgs e)
        {

        }

        private void button18_Click(object sender, EventArgs e)
        {

        }
    }
}
