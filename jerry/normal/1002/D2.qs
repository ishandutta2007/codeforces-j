namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit, b : Int[]) : ()
    {
        body
        {
            for (i in 0 .. Length(x)-1) {
                CNOT(x[i], y);
            }
            for (i in 0 .. Length(b)-1) {
                if (b[i] == 0) {
                    X(y);
                }
            }
        }
    }
}