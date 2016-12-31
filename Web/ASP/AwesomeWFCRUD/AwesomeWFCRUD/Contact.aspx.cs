using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace AwesomeWFCRUD
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        //Fetch Countries

        private List<Country> PopulateCountry()
        {
            using (MyDatabaseEntities dc = new MyDatabaseEntities())
            {
                return dc.Countries.OrderBy(a => a.CountryName).ToList();
            }
        }

    }
}