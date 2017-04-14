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
                            dataItems.Text = sqlReader["Food Name"].ToString();
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
    }
}