using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace UserAuth1
{
    public partial class ListItemPage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void ItemSelected(object sender, EventArgs e)
        {
            Int32 totalVal = 0;
            foreach (ListItem item in CheckBoxList1.Items)
            {
                totalVal += Convert.ToInt32(item.Value);

            }

            Label1.Text = totalVal.ToString();
        }
    }
}