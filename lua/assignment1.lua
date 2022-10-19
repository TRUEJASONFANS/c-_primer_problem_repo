a = [===[
<![CDATA[
 Hello world
 ]]\>
]===]
print(a)

local function insert(s, index, sub_string)
    return string.sub(s, 1, index - 1) .. sub_string .. string.sub(s, index - 1, #s)
end

print (insert("hello world", 1, "start: ") )
print (insert("hello world", 7, "small "))


function natural_index(index)
    return type(index) == "number" and index > 0 and math.floor(index) == index
end

function valid_no_borders(t)
    result = true
    for k in pairs(t) do
        if natural_index(k) then
            result = false
            break
        end
    end

    return t[1] == nil and result
end

local function testSequence(s)
    local border = 0
    if s[1] ~= nil then
        for index in pairs(s) do
            if natural_index(index) and t[index + 1] == nil then
                borders = borders + 1
                if borders > 1 then
                    break
                end
            end
        end
    end
    return borders == 1 or valid_no_borders(t) and borders == 0
end