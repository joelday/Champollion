using System;
using Champollion;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ChampollionManagedTests
{
    [TestClass]
    public class PexConvertTest
    {
        private byte[] ReadTestPexBytes()
        {
            return System.IO.File.ReadAllBytes("Math.pex");
        }

        [TestMethod]
        public void ConvertToPsc()
        {
            var psc = PexConvert.ToPsc(ReadTestPexBytes());
            Assert.IsNotNull(psc);
            Console.WriteLine(psc);
        }
    }
}
