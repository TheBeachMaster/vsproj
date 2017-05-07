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
        /// Gets a list of restaurants from the DB and populates them
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
                    sqlCmd.CommandText = "SELECT * FROM Restaurants ";
                    sqlCmd.Connection = sqlConn;

                    //Open Connection to SQL Server Instance

                    sqlConn.Open();

                    //Read Data and Nuke 
                    using (SqlDataReader sqlReader = sqlCmd.ExecuteReader())
                    {
                        while (sqlReader.Read()) //Read All Items
                        {
                            ListItem restaurants = new ListItem();

                            restaurants.Text = sqlReader["Restaurant Name"].ToString();
                            restaurants.Value = sqlReader["Restaurant Name"].ToString();
                            restaurants.Selected = false;
                            RestaurantList.Items.Add(restaurants);

                           
                        }
                        
                    }

                    sqlConn.Close();
                    //Close all connections
                }
            }
        }

        protected void SubmitRest(object sender, EventArgs e)
        {

            string rest = RestaurantList.SelectedItem.Value.ToString();
            if (rest.Length == 0)
            {
                //TODO :Fix Empty Bug
                RestLabel.Text = "You need to select at least a resaturant";
            }
            else
            {
                
                RestLabel.Text = rest;
            }

            //using (SqlConnection sqlConn = new SqlConnection())
            //{
            //    sqlConn.ConnectionString = ConfigurationManager.ConnectionStrings["transact"].ConnectionString;

            //    using (SqlCommand sqlCmd = new SqlCommand())
            //    {
            //        sqlCmd.CommandText = "SELECT * FROM [MainTable] WHERE ([Menu] =Breakfast AND [Restaurant Name]=@rest) ";
            //        sqlCmd.Connection = sqlConn;

            //        //Open Connection to SQL Server Instance

            //        sqlConn.Open();

            //        //Read Data and Nuke 
            //        using (SqlDataReader sqlReader = sqlCmd.ExecuteReader())
            //        {
            //            while (sqlReader.Read()) //Read All Items
            //            {
            //                ListItem restaurants = new ListItem();

            //                restaurants.Text = sqlReader["Food Item"].ToString();
            //                restaurants.Value = sqlReader["Price"].ToString();
            //                restaurants.Selected = false;
            //                BreakfastList.Items.Add(restaurants);


            //            }

            //        }

            //        sqlConn.Close();
            //        //Close all connections
            //    }
            //}

        }
    }
}