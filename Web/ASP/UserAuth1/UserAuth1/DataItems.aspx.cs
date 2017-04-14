using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Configuration;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace UserAuth1
{
    public partial class DataItems : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                //Ensure Items load when the page is launched
                this.PopulateItems();
            }
        }

        protected void AddItems(object sender, EventArgs e)
        {
            //You can have the User's name added here to DB  for submission
            //This Data Goes to a Separate Table
            //Proc....
            /* 1.Get Connnection String
             * 2.Open Connection
             * 3.Execute Query
             * 4.Close Connection
            */
            using (SqlConnection sqlCon = new SqlConnection())
            {
                Int32 totalVal = 0;
                sqlCon.ConnectionString = ConfigurationManager.ConnectionStrings["foodConstr"].ConnectionString;
                using (SqlCommand sqlCmd = new SqlCommand())
                {
                    sqlCmd.CommandText = "INSERT INTO Submit(TotalVal) VALUES(@TotalVal)";

                    sqlCmd.Connection = sqlCon;
                    sqlCon.Open();
                    
                    for (int i = 0; i < FoodItemsList.Items.Count; i++)
                    {
                        //check if particular items is selected or not
                        if (FoodItemsList.Items[i].Selected)
                        {
                            //If selected then add the values to textbox
                            totalVal += Convert.ToInt32(FoodItemsList.Items[i].Value);
                        }
                    }
                    sqlCmd.Parameters.Clear();
                    sqlCmd.Parameters.AddWithValue("@TotalVal", totalVal);
                    sqlCmd.ExecuteNonQuery();
                    sqlCon.Close();
                }
                Response.Redirect(Request.Url.AbsoluteUri);
            }

        }

        private void PopulateItems()
        {
            using (SqlConnection sqlConn = new SqlConnection())
            {
                sqlConn.ConnectionString = ConfigurationManager.ConnectionStrings["foodConstr"].ConnectionString;

                using (SqlCommand sqlCmd = new SqlCommand())
                {
                    sqlCmd.CommandText = "SELECT * FROM FoodItems";
                    sqlCmd.Connection = sqlConn;

                    //Open Connection to SQL Server Instance

                    sqlConn.Open();

                    //Read Data and Nuke 
                    using (SqlDataReader sqlReader = sqlCmd.ExecuteReader())
                    {
                        while (sqlReader.Read()) //Read All Items
                        {
                            ListItem dataItems = new ListItem();
                            
                            dataItems.Text = sqlReader["Food Name"].ToString() + "  @ Ksh . "+ "    "+ sqlReader["Food Price"].ToString();
                            dataItems.Value = sqlReader["Food Price"].ToString();
                            dataItems.Selected = Convert.ToBoolean(sqlReader["Selected"]);
                            FoodItemsList.Items.Add(dataItems);
                        }
                    }

                    sqlConn.Close();
                    //Close all connections
                }
            }
        }

        protected void GetTotals(object sender, EventArgs e)
        {
            //Remember THIS Function()?

            Int32 totalvalue = 0;
            //Loop through items in checkboxlist
            for (int i = 0; i < FoodItemsList.Items.Count; i++)
            {
                //check if particular items is selected or not
                if (FoodItemsList.Items[i].Selected)
                {
                    //If selected then add the values to textbox
                    totalvalue += Convert.ToInt32(FoodItemsList.Items[i].Value);


                }
            }
            
        }
    }
}