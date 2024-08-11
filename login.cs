using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace FinalRS
{
    public partial class LogIn : Form
    {
        SqlConnection cs = new SqlConnection(@"Data Source=.\SQLEXPRESS;AttachDbFilename=C:\Users\Kousik kundu\Documents\Visual Studio 2005\Projects\FinalRS\FinalRS\Database1.mdf;Integrated Security=True;User Instance=True");
        SqlCommand cmd = new SqlCommand();
        SqlDataAdapter dr;

        public LogIn()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            Application.Exit();

        }
        private void LogIn_Load(object sender, EventArgs e)
        {
            cmd.Connection = cs;

        }
        private void btnLogIn_Click(object sender, EventArgs e)
        {
            cs.Open();
            StringBuilder stb = new StringBuilder();
            stb.Append("select * from tbUser where UserName = '" + txtUserName.Text + "'");
            cmd.CommandText = stb.ToString();
            cmd.CommandType = CommandType.Text;
            SqlDataReader reader = cmd.ExecuteReader();
            if (!reader.Read())
                MessageBox.Show("Enter valid User Name");
            else
            {
                String pass = reader["Password"].ToString();
                if (pass != txtPassword.Text.Trim())
                    MessageBox.Show("Password not matched");
                else
                {
                    if (reader["UserType"].ToString() == "Manager")
                    {
                        
                        MessageBox.Show(" Are You a Manager");
                        this.Hide();
                        Manager f1 = new Manager(txtUserName.Text);
                        f1.Show();
                    }
                    else
                    {
                        MessageBox.Show("Are You an User");

                        this.Hide();
                        User f2 = new User(txtUserName.Text);
                        f2.Show();
                    }
                }

            }
            cmd.Dispose();
            cs.Close();
        }
    }
}
    