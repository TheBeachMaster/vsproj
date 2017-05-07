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
    public partial class Menus : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                this.GetRestaurants();
            }
        }

        /// <summary>
        /// Gets a list of restarants from the DB and populates them
        /// main page.
        /// This function is loaded first when the page loads
        /// </summary>
        private void GetRestaurants()
        {
            using (SqlConnection sqlConn = new SqlConnection())
            {
                sqlConn.ConnectionString = ConfigurationManager.ConnectionStrings["transact"].ConnectionString;

                using (SqlCommand sqlCmd = new SqlCommand())
                {
                    sqlCmd.CommandText = "SELECT * FROM Restaurants";
                    sqlCmd.Connection = sqlConn;

                    //Open Connection to SQL Server Instance

                    sqlConn.Open();

                    //Read Data and Nuke 
                    using (SqlDataReader sqlReader = sqlCmd.ExecuteReader())
                    {
                        while (sqlReader.Read()) //Read All Items
                        {
                            ListItem restarants = new ListItem();

                            restarants.Text = sqlReader["Restaurant Name"].ToString();
                            restarants.Value = sqlReader["Restaurant Name"].ToString();
                            restarants.Selected = false;
                            RestaurantList.Items.Add(restarants);
                        }
                    }

                    sqlConn.Close();
                    //Close all connections
                }
            }
        }
    }
}