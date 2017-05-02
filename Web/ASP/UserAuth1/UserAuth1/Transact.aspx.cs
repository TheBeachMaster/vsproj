using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace UserAuth1
{
    public partial class Transact : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void LaunchPayModal(object sender, EventArgs e)
        {
            lblModalTitle.Text = "Arthur's Caffe Cashier";
            ScriptManager.RegisterStartupScript(Page, Page.GetType(), "transactModal", "$('#transactModal').modal();", true);
            upModal.Update();
        }

        protected void GetTotals(object sender, EventArgs e)
        {
            Int32 totalvalue = 0;
            Label2.Text = " ";
            //Loop through items in checkboxlist
            for (int i = 0; i < ItemsList.Items.Count; i++)
            {
                //check if particular items is selected or not
                if (ItemsList.Items[i].Selected)
                {
                    //If selected then add the values to textbox
                    totalvalue += Convert.ToInt32(ItemsList.Items[i].Value);


                }
            }

            Label2.Text += $"Your total is Ksh:  {totalvalue.ToString()}";
           
        }

        protected void PayMpesa(object sender, EventArgs e)
        {
            Label1.Text = " ";
            using (SqlConnection sqlCon = new SqlConnection())
            {
                sqlCon.ConnectionString = ConfigurationManager.ConnectionStrings["mpesaCon"].ConnectionString;

                using (SqlCommand sqlCmd = new SqlCommand())
                {
                    sqlCmd.CommandText = "SELECT COUNT(*) FROM [Transact] WHERE ([TransactionID] = @transactId)";
                    sqlCmd.Connection = sqlCon;
                    sqlCon.Open();

                    sqlCmd.Parameters.AddWithValue("@transactId", txtTransact.Text);
                    int transact = (int)sqlCmd.ExecuteScalar();

                    if (transact > 0)
                    {
                        Label1.Text += $"Payment Verified";
                    }
                    else
                    {
                        Label1.CssClass = "danger";
                        Label1.Text += "Payment not Verified";
                    }
                }
            }
        }
    }
}