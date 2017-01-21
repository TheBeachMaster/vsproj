using App1.Model;

namespace App1.Interfaces
{
    public interface IMyItemStore : IBaseStore<MyItem>
    {
        //Add additional interface methods
        //specific to this data store.
    }
}
