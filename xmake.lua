set_project("CP-Problems")

add_rules("mode.debug", "mode.release")

function AddProblem(probName)
    targets = {"checker", "generator", "solution", "validator"}

    for _, targetName in pairs(targets) do 
        target(targetName)
            set_languages("cxx23")
            set_kind("binary")
            set_warnings("all", "error")

            add_files("problem/" .. probName .. "/" .. targetName .. ".cpp")
            add_includedirs("lib")
            add_includedirs(".")

            after_build(function (target)
                os.cp(target:targetfile(), "bin/" .. probName .. "/")
            end)
        target_end()
    end 
end

AddProblem("sort-by-swap")
