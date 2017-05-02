using System;
using System.Collections.Generic;
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
    }
}